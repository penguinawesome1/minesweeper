#include "user_input.hpp"
#include "../../core/collision.hpp"
#include "helpers.hpp"

namespace game::helpers {

void handle_left_click(ClickParams &params) {
  // face button
  if (core::is_mouse_collision(params.window,
                               params.buttons.face_button.getGlobalBounds())) {
    params.game.reset();
    return;
  }

  // pause button
  if (params.board.state == components::Board::State::IN_PROGRESS &&
      core::is_mouse_collision(params.window,
                               params.buttons.pause_button.getGlobalBounds())) {
    params.game.toggle_pause();
    return;
  }

  // leaderboard button
  if (core::is_mouse_collision(
          params.window, params.buttons.leaderboard_button.getGlobalBounds())) {

    const bool was_already_paused = params.game.get_pause();

    params.game.pause();
    open_leaderboard(params.config, params.game.get_updated_leaderboard_pos());
    if (!was_already_paused)
      params.game.unpause();
    return;
  }

  if (params.is_paused ||
      params.board.state != components::Board::State::IN_PROGRESS) {
    return;
  }

  // debug button
  if (core::is_mouse_collision(params.window,
                               params.buttons.debug_button.getGlobalBounds())) {
    params.board.is_debug_mode = !params.board.is_debug_mode;
    return;
  }

  const sf::Vector2i mouse_pos = sf::Mouse::getPosition(params.window);

  params.board.try_reveal(mouse_pos.x / params.config.sq_length,
                          mouse_pos.y / params.config.sq_length);
}

void handle_right_click(ClickParams &params) {
  const sf::Vector2i mouse_pos = sf::Mouse::getPosition(params.window);

  if (params.is_paused) {
    return;
  }

  if (auto tile = params.board.at(mouse_pos.x / params.config.sq_length,
                                  mouse_pos.y / params.config.sq_length);
      tile->get().is_hidden) {
    bool &is_flagged = tile->get().is_flagged;
    is_flagged = !is_flagged;
    params.flag_manager.add_to_flag_count(is_flagged ? -1 : 1);
  }
}

} // namespace game::helpers
