#pragma once

#include "../../managers/AssetManager.hpp"
#include "../components/Board.hpp"
#include <SFML/Graphics.hpp>

namespace game::helpers {

struct DrawBoardParams {
  components::Board &board;
  sf::RenderWindow &window;
  const managers::AssetManager &asset_manager;
  const size_t sq_length;
  const bool is_paused;
};

void draw_board(DrawBoardParams &params);

} // namespace game::helpers