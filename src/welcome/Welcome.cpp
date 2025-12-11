#include "Welcome.hpp"
#include "components/ui_builder.hpp"

namespace welcome {

auto Welcome::run() -> bool {
  const sf::Vector2u window_size = window_.getSize();

  while (window_.isOpen()) {
    sf::Event event;

    while (window_.pollEvent(event)) {
      if (event.type == sf::Event::Closed)
        window_.close();

      if (event.type != sf::Event::TextEntered)
        continue;

      if (event.text.unicode == '\r' && user_name_.size() != 0)
        return true;

      update_user_name(event.text.unicode);
    }

    TextManager::update_player_name_text(window_size, user_name_);
    draw();
  }

  return false;
}

void Welcome::update_user_name(const sf::Uint32 next_c,
                               const size_t max_input_size) {
  if (next_c >= 128)
    return;

  const size_t user_name_size = user_name_.size();

  if (next_c == '\b' && !user_name_.empty()) {
    user_name_.pop_back();
    return;
  }

  if (user_name_size < max_input_size && std::isalpha(next_c)) {
    user_name_ += user_name_size == 0 ? toupper(next_c) : tolower(next_c);
  }
}

void Welcome::draw() {
  window_.clear(sf::Color::Blue);
  window_.draw(TextManager::welcome_to_minesweeper_text);
  window_.draw(TextManager::enter_your_name_text);
  window_.draw(TextManager::player_name_text);
  window_.display();
}

}; // namespace welcome
