#pragma once

#include "../../config/Config.hpp"
#include "../../managers/AssetManager.hpp"
#include "Board.hpp"

namespace game::components {

struct Buttons {
  Buttons(const config::Config &config,
          const managers::AssetManager &asset_manager);

  sf::Sprite face_button, debug_button, pause_button, leaderboard_button;
};

} // namespace game::components
