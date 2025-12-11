#pragma once

#include <SFML/Graphics.hpp>

namespace leaderboard::components {

[[nodiscard]] auto get_leaderboard_text(const sf::Font &font,
                                        const sf::Vector2u window_size)
    -> sf::Text;

[[nodiscard]] auto get_leaderboard_info_text(const sf::Font &font,
                                             const sf::Vector2u window_size,
                                             std::string info) -> sf::Text;

} // namespace leaderboard::components