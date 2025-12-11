#include "Buttons.hpp"
#include "ui_builder.hpp"

namespace game::components {

Buttons::Buttons(const config::Config &config,
                 const managers::AssetManager &asset_manager)
    : face_button(get_happy_face_button(config, asset_manager)),
      debug_button(get_debug_button(config, asset_manager)),
      pause_button(get_pause_button(config, asset_manager)),
      leaderboard_button(get_leaderboard_button(config, asset_manager)) {}

} // namespace game::components