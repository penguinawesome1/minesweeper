#include "ui_builder.hpp"
#include "../../core/helpers/helpers.hpp"

namespace leaderboard::components {

[[nodiscard]] auto get_leaderboard_text(const sf::Font &font,
                                        const sf::Vector2u window_size)
    -> sf::Text {
  sf::Text text;
  text.setString("LEADERBOARD");
  text.setFont(font);
  text.setCharacterSize(20);
  text.setStyle(sf::Text::Bold | sf::Text::Underlined);
  core::helpers::set_center_pos(text, window_size.x / 2,
                                window_size.y / 2 - 120);
  return text;
}

[[nodiscard]] auto get_leaderboard_info_text(const sf::Font &font,
                                             const sf::Vector2u window_size,
                                             std::string info) -> sf::Text {
  sf::Text text;
  text.setString(std::move(info));
  text.setFont(font);
  text.setCharacterSize(18);
  text.setStyle(sf::Text::Bold);
  core::helpers::set_center_pos(text, window_size.x / 2,
                                window_size.y / 2 + 20);
  return text;
}

} // namespace leaderboard::components