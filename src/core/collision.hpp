#pragma once

#include <SFML/Graphics.hpp>

namespace core {

/**
 * # Source
 *
 * https://stackoverflow.com/questions/23530360/how-do-you-make-a-clickable-sprite-in-sfml
 */
auto is_mouse_collision(const sf::Window &window, const sf::FloatRect box)
    -> bool;

} // namespace core