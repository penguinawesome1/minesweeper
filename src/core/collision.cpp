#include "collision.hpp"

namespace core {

auto is_mouse_collision(const sf::Window &window, const sf::FloatRect box)
    -> bool {
  const sf::Vector2i mouse_pos = sf::Mouse::getPosition(window);

  return mouse_pos.x > box.left && mouse_pos.x < box.left + box.width &&
         mouse_pos.y > box.top && mouse_pos.y < (box.top + box.height);
}

} // namespace core