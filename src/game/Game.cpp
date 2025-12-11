#include "Game.hpp"
#include "../leaderboard/io/file_io.hpp"
#include "helpers/helpers.hpp"
#include "helpers/renderer.hpp"
#include "helpers/user_input.hpp"

namespace game {

Game::Game(const config::Config &config, sf::RenderWindow &window,
           std::string name)
    : config_(config),
      asset_manager_(managers::AssetManager(config.image_paths)),
      board_(components::Board(config.num_rows, config.num_cols,
                               config.num_mines)),
      timer_manager_(components::TimerManager(config, asset_manager_)),
      flag_manager_(components::FlagManager(config, asset_manager_)),
      buttons_(components::Buttons(config, asset_manager_)), window_(window),
      name_(std::move(name)), is_paused_(false) {
  timer_manager_.update_timer_digits();
  flag_manager_.update_flag_digits();
}

void Game::run() {
  while (window_.isOpen()) {
    sf::Event event;

    while (window_.pollEvent(event))
      try_handle_input(event);

    if (!is_paused_ && board_.state == components::Board::State::IN_PROGRESS) {
      timer_manager_.update_time();
      board_.update_state();

      if (board_.state == components::Board::State::WIN)
        handle_win();
    }

    helpers::update_face_button(buttons_.face_button, asset_manager_,
                                board_.state);

    draw();
  }
}

void Game::handle_win() {
  const std::string time = helpers::format_time(timer_manager_.get_time());
  updated_leaderboard_pos_ = leaderboard::io::update_leaderboard(
      config_.leaderboard_path, name_, time);
  flag_manager_.set_flag_count(0);
}

void Game::try_handle_input(const sf::Event event) {
  if (event.type == sf::Event::Closed)
    window_.close();

  if (event.type == sf::Event::MouseButtonReleased) {
    helpers::ClickParams params{board_,   config_,       window_, is_paused_,
                                buttons_, flag_manager_, *this};

    if (event.mouseButton.button == sf::Mouse::Left)
      helpers::handle_left_click(params);

    if (event.mouseButton.button == sf::Mouse::Right &&
        board_.state == components::Board::State::IN_PROGRESS)
      helpers::handle_right_click(params);
  }
}

void Game::draw() {
  window_.clear(sf::Color::White);
  window_.draw(buttons_.face_button);
  window_.draw(buttons_.debug_button);
  window_.draw(buttons_.pause_button);
  window_.draw(buttons_.leaderboard_button);

  helpers::DrawBoardParams params = {board_, window_, asset_manager_,
                                     config_.sq_length, is_paused_};
  helpers::draw_board(params);

  flag_manager_.draw(window_);
  timer_manager_.draw(window_);

  window_.display();
}

void Game::reset() {
  board_ =
      components::Board(config_.num_rows, config_.num_cols, config_.num_mines);
  flag_manager_.set_flag_count(config_.num_mines);
  timer_manager_.reset_time();
  is_paused_ = false;
}

void Game::pause() {
  is_paused_ = true;
  buttons_.pause_button.setTexture(*asset_manager_.get_texture("play"));
  timer_manager_.clear_frame_time();
  draw();
}

void Game::unpause() {
  is_paused_ = false;
  buttons_.pause_button.setTexture(*asset_manager_.get_texture("pause"));
  timer_manager_.clear_frame_time();
  draw();
}

} // namespace game