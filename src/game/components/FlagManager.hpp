#pragma once

#include "../../config/Config.hpp"
#include "../../managers/AssetManager.hpp"
#include <SFML/Graphics.hpp>
#include <array>

namespace game::components {

class FlagManager {
public:
  FlagManager(const config::Config &config,
              const managers::AssetManager &asset_manager);
  void update_flag_digits();
  void draw(sf::RenderWindow &window);

  void add_to_flag_count(const int n) {
    flag_count_ += n;
    update_flag_digits();
  }

  void set_flag_count(const size_t n) {
    flag_count_ = n;
    update_flag_digits();
  }

private:
  const config::Config &config_;
  const managers::AssetManager &asset_manager_;
  std::array<sf::Sprite, 3> flag_digits_;
  int flag_count_;
};

} // namespace game::components