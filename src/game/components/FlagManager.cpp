#include "FlagManager.hpp"
#include "ui_builder.hpp"

namespace game::components {

FlagManager::FlagManager(const config::Config &config,
                         const managers::AssetManager &asset_manager)
    : config_(config), asset_manager_(asset_manager) {
  set_flag_count(config.num_mines);
}

void FlagManager::update_flag_digits() {
  flag_digits_ = {
      get_counter_digit(config_, asset_manager_, 0, flag_count_ >= 0 ? 0 : 10),
      get_counter_digit(config_, asset_manager_, 1, std::abs(flag_count_) / 10),
      get_counter_digit(config_, asset_manager_, 2,
                        std::abs(flag_count_) % 10)};
}

void FlagManager::draw(sf::RenderWindow &window) {
  for (const sf::Sprite d : flag_digits_) {
    window.draw(d);
  }
}

} // namespace game::components