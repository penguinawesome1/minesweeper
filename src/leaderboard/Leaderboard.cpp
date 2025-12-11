#include "Leaderboard.hpp"
#include "components/ui_builder.hpp"
#include "io/file_io.hpp"
#include <iostream>

namespace leaderboard {

Leaderboard::Leaderboard(sf::RenderWindow &window, const config::Config &config,
                         const std::optional<size_t> updated_leaderboard_pos)
    : window_(window), config_(config),
      updated_leaderboard_pos_(updated_leaderboard_pos) {
  if (!font_.loadFromFile(config.font_path)) {
    std::cerr << "Failed to load font from config path:" << config.font_path
              << "\n";
  }

  leaderboard_text_ = components::get_leaderboard_text(font_, window.getSize());
  leaderboard_info_text_ = get_leaderboard_info_text_wrapper();
}

void Leaderboard::run() {
  const sf::Vector2u window_size = window_.getSize();

  while (window_.isOpen()) {
    sf::Event event;

    while (window_.pollEvent(event)) {
      if (event.type == sf::Event::Closed)
        window_.close();
    }

    draw();
  }
}

void Leaderboard::draw() {
  window_.clear(sf::Color::Blue);
  window_.draw(leaderboard_text_);
  window_.draw(leaderboard_info_text_);
  window_.display();
}

[[nodiscard]] auto Leaderboard::format_leaderboard_info(const auto info)
    -> std::string {
  const size_t info_size = info.size();
  std::string temp = "";

  for (size_t i = 0; i < info_size; i++) {
    temp += std::to_string(i + 1) + ".\t" + info[i].time + "\t" + info[i].name;
    if (updated_leaderboard_pos_ && i == *updated_leaderboard_pos_) {
      temp += "*";
    }
    temp += "\n\n";
  }

  return temp;
}

[[nodiscard]] auto Leaderboard::get_leaderboard_info_text_wrapper()
    -> sf::Text {
  const auto info = io::get_leaderboard_info(config_.leaderboard_path);
  std::string info_str = format_leaderboard_info(info);
  return components::get_leaderboard_info_text(font_, window_.getSize(),
                                               std::move(info_str));
}

} // namespace leaderboard
