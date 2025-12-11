#pragma once

#include "../config/Config.hpp"
#include <SFML/Graphics.hpp>
#include <optional>

namespace leaderboard {

class Leaderboard {
public:
  Leaderboard(sf::RenderWindow &window, const config::Config &config,
              const std::optional<size_t> updated_leaderboard_pos);
  void run();
  void draw();
  [[nodiscard]] auto get_leaderboard_info_text_wrapper() -> sf::Text;
  [[nodiscard]] auto format_leaderboard_info(const auto info) -> std::string;

private:
  const config::Config &config_;
  const std::optional<size_t> updated_leaderboard_pos_;
  sf::Font font_;
  sf::RenderWindow &window_;
  sf::Text leaderboard_text_;
  sf::Text leaderboard_info_text_;
};

} // namespace leaderboard