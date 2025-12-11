#pragma once

#include "../../config/Config.hpp"
#include "../../managers/AssetManager.hpp"
#include <SFML/Graphics.hpp>

namespace game::components {

[[nodiscard]] auto
get_happy_face_button(const config::Config &config,
                      const managers::AssetManager &asset_manager)
    -> sf::Sprite;

[[nodiscard]] auto get_debug_button(const config::Config &config,
                                    const managers::AssetManager &asset_manager)
    -> sf::Sprite;

[[nodiscard]] auto get_pause_button(const config::Config &config,
                                    const managers::AssetManager &asset_manager)
    -> sf::Sprite;

[[nodiscard]] auto
get_leaderboard_button(const config::Config &config,
                       const managers::AssetManager &asset_manager)
    -> sf::Sprite;

[[nodiscard]] auto
get_counter_digit(const config::Config &config,
                  const managers::AssetManager &asset_manager, const int index,
                  const int shift) -> sf::Sprite;

[[nodiscard]] auto get_timer_digit(const config::Config &config,
                                   const managers::AssetManager &asset_manager,
                                   const int index, const int shift)
    -> sf::Sprite;

} // namespace game::components