#pragma once

#include "../../config/Config.hpp"
#include <SFML/Graphics.hpp>

namespace welcome::components {

struct TextManager {
  sf::Text welcome_to_minesweeper_text, enter_your_name_text, player_name_text;

  TextManager(const config::Config &config, const sf::Vector2u window_size);

  void update_player_name_text(const sf::Vector2u window_size,
                               std::string user_name);

private:
  sf::Font font_;
};

} // namespace welcome::components