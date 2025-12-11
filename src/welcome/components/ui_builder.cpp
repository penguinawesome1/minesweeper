#include "ui_builder.hpp"
#include "../../core/helpers/helpers.hpp"

namespace welcome::components {

[[nodiscard]] auto get_player_name_text(const sf::Font &font,
                                        const sf::Vector2u window_size,
                                        std::string str) -> sf::Text {
  sf::Text text;
  text.setString(std::move(str));
  text.setFont(font);
  text.setCharacterSize(18);
  text.setStyle(sf::Text::Bold);
  text.setFillColor(sf::Color::Yellow);
  core::helpers::set_center_pos(text, window_size.x / 2,
                                window_size.y / 2 - 45);
  return text;
}

[[nodiscard]] auto
get_welcome_to_minesweeper_text(const sf::Font &font,
                                const sf::Vector2u window_size) -> sf::Text {
  sf::Text text;
  text.setString("WELCOME TO MINESWEEPER!");
  text.setFont(font);
  text.setCharacterSize(24);
  text.setStyle(sf::Text::Bold | sf::Text::Underlined);
  core::helpers::set_center_pos(text, window_size.x / 2,
                                window_size.y / 2 - 150);
  return text;
}

[[nodiscard]] auto get_enter_your_name_text(const sf::Font &font,
                                            const sf::Vector2u window_size)
    -> sf::Text {
  sf::Text text;
  text.setString("Enter your name:");
  text.setFont(font);
  text.setCharacterSize(20);
  text.setStyle(sf::Text::Bold);
  core::helpers::set_center_pos(text, window_size.x / 2,
                                window_size.y / 2 - 75);
  return text;
}

} // namespace welcome::components