#pragma once
#include "../../config/Config.hpp"
#include "../../managers/AssetManager.hpp"
#include <SFML/Graphics.hpp>
#include <array>

namespace game::components {

class TimerManager : private sf::Clock {
public:
  TimerManager(const config::Config &config,
               const managers::AssetManager &asset_manager);
  void update_time();
  void update_timer_digits();
  void draw(sf::RenderWindow &window);

  auto get_time() -> float { return total_time_; }

  void clear_frame_time() { Clock::restart(); }

  auto get_digits() -> const std::array<sf::Sprite, 4> & {
    return timer_digits_;
  }

  void reset_time() {
    total_time_ = 0.0;
    Clock::restart();
  }

private:
  const config::Config &config_;
  const managers::AssetManager &asset_manager_;
  std::array<sf::Sprite, 4> timer_digits_;
  float total_time_ = 0.0;
};

} // namespace game::components