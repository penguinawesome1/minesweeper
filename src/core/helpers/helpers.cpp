#include "helpers.hpp"

namespace core::helpers {

void set_center_pos(sf::Text &text, const size_t x, const size_t y) {
  sf::FloatRect textRect = text.getLocalBounds();
  text.setOrigin(textRect.left + textRect.width / 2.0f,
                 textRect.top + textRect.height / 2.0f);
  text.setPosition(sf::Vector2f(x, y));
}

} // namespace core::helpers