#pragma once

#include <SFML/Graphics.hpp>

namespace welcome::components {

[[nodiscard]] auto get_player_name_text(const sf::Font &font,
                                        const sf::Vector2u window_size,
                                        std::string str) -> sf::Text;

[[nodiscard]] auto
get_welcome_to_minesweeper_text(const sf::Font &font,
                                const sf::Vector2u window_size) -> sf::Text;

[[nodiscard]] auto get_enter_your_name_text(const sf::Font &font,
                                            const sf::Vector2u window_size)
    -> sf::Text;

} // namespace welcome::components