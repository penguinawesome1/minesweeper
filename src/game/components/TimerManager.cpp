#include "TimerManager.hpp"
#include "ui_builder.hpp"

namespace game::components {

TimerManager::TimerManager(const config::Config &config,
                           const managers::AssetManager &asset_manager)
    : config_(config), asset_manager_(asset_manager) {
  update_timer_digits();
}

void TimerManager::update_time() {
  const sf::Time elapsed = Clock::getElapsedTime();
  const sf::Time frameTime = Clock::restart();
  total_time_ += elapsed.asSeconds();
  update_timer_digits();
}

void TimerManager::update_timer_digits() {
  int minutes = total_time_ / 60;
  int seconds = static_cast<int>(total_time_) % 60;

  timer_digits_ = {
      components::get_timer_digit(config_, asset_manager_, 0, minutes / 10),
      components::get_timer_digit(config_, asset_manager_, 1, minutes % 10),
      components::get_timer_digit(config_, asset_manager_, 2, seconds / 10),
      components::get_timer_digit(config_, asset_manager_, 3, seconds % 10)};
}

void TimerManager::draw(sf::RenderWindow &window) {
  for (const sf::Sprite d : timer_digits_) {
    window.draw(d);
  }
}

} // namespace game::components