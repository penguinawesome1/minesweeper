#include "helpers.hpp"
#include "../../leaderboard/Leaderboard.hpp"
#include "../components/ui_builder.hpp"
#include <optional>

namespace game::helpers {

auto format_time(float time) -> std::string {
  int minutes = time / 60;
  int seconds = static_cast<int>(time) % 60;

  return "" + std::to_string(minutes / 10) + std::to_string(minutes % 10) +
         ":" + std::to_string(seconds / 10) + std::to_string(seconds % 10);
}

void update_face_button(sf::Sprite &face_button,
                        const managers::AssetManager &asset_manager,
                        const components::Board::State state) {
  const std::unordered_map<components::Board::State, std::string> pairs = {
      {components::Board::State::IN_PROGRESS, "face_happy"},
      {components::Board::State::WIN, "face_win"},
      {components::Board::State::LOSE, "face_lose"}};

  face_button.setTexture(*asset_manager.get_texture(pairs.at(state)));
}

void open_leaderboard(const config::Config &config,
                      const std::optional<size_t> updated_leaderboard_pos) {
  sf::RenderWindow window(
      sf::VideoMode(config.num_cols * config.sq_length * 0.5,
                    config.num_rows * config.sq_length * 0.5 + 50),
      "Minesweeper", sf::Style::Close);
  leaderboard::Leaderboard leaderboard =
      leaderboard::Leaderboard(window, config, updated_leaderboard_pos);
  leaderboard.run();
}

} // namespace game::helpers