#include "TextManager.hpp"
#include "ui_builder.hpp"
#include <iostream>
#include <string>

namespace welcome::components {

TextManager::TextManager(const config::Config &config,
                         const sf::Vector2u window_size) {
  if (!font_.loadFromFile(config.font_path)) {
    std::cerr << "Failed to load font from config path:" << config.font_path
              << "\n";
  }

  welcome_to_minesweeper_text =
      get_welcome_to_minesweeper_text(font_, window_size);
  enter_your_name_text = get_enter_your_name_text(font_, window_size);
}

void TextManager::update_player_name_text(const sf::Vector2u window_size,
                                          std::string user_name) {
  player_name_text =
      get_player_name_text(font_, window_size, std::move(user_name) + "|");
}

} // namespace welcome::components