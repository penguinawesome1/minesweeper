#pragma once

#include "../../managers/AssetManager.hpp"
#include "../components/Board.hpp"
#include <SFML/Graphics.hpp>
#include <string>

namespace game::helpers {

auto format_time(float time) -> std::string;

void update_face_button(sf::Sprite &face_button,
                        const managers::AssetManager &asset_manager,
                        const components::Board::State state);

void open_leaderboard(const config::Config &config,
                      const std::optional<size_t> updated_leaderboard_pos);

} // namespace game::helpers
