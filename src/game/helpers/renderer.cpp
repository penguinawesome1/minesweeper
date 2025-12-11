#include "renderer.hpp"

namespace game::helpers {

namespace {

void draw(sf::RenderWindow &window, const size_t x, const size_t y,
          const sf::Texture &texture) {
  sf::Sprite sprite;
  sprite.setTexture(texture);
  sprite.setPosition(x, y);
  window.draw(sprite);
}

void draw_board_all_revealed(DrawBoardParams &params) {
  params.board.for_tile([&](size_t x, size_t y, components::Board::Tile &tile) {
    draw(params.window, x * params.sq_length, y * params.sq_length,
         *params.asset_manager.get_texture("tile_revealed"));
  });
}

void draw_board_debug(DrawBoardParams &params) {
  auto call_draw = [&](const size_t x, const size_t y,
                       const std::string &texture_name) {
    draw(params.window, x * params.sq_length, y * params.sq_length,
         *params.asset_manager.get_texture(texture_name));
  };

  params.board.for_tile([&](size_t x, size_t y, components::Board::Tile &tile) {
    call_draw(x, y, tile.is_hidden ? "tile_hidden" : "tile_revealed");

    if (tile.is_flagged)
      call_draw(x, y, "flag");

    if (tile.is_mine)
      call_draw(x, y, "mine");
    else if (tile.num_adj_mines && !tile.is_hidden)
      call_draw(x, y, "number_" + std::to_string(tile.num_adj_mines));
  });
}

} // namespace

void draw_board(DrawBoardParams &params) {
  if (params.is_paused) {
    draw_board_all_revealed(params);
    return;
  }

  if (params.board.is_debug_mode) {
    draw_board_debug(params);
    return;
  }

  params.board.for_tile([&](size_t x, size_t y, components::Board::Tile &tile) {
    auto call_draw = [&](const size_t x, const size_t y,
                         const std::string &texture_name) {
      draw(params.window, x * params.sq_length, y * params.sq_length,
           *params.asset_manager.get_texture(texture_name));
    };

    call_draw(x, y, tile.is_hidden ? "tile_hidden" : "tile_revealed");

    if (tile.is_flagged)
      call_draw(x, y, "flag");
    else if (tile.num_adj_mines && !tile.is_hidden)
      call_draw(x, y, "number_" + std::to_string(tile.num_adj_mines));
  });
}

} // namespace game::helpers