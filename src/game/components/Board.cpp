#include "Board.hpp"
#include "../../core/collision.hpp"
#include <algorithm>
#include <iostream>
#include <random>

namespace game::components {

Board::Board(const size_t num_rows, const size_t num_cols,
             const size_t num_mines)
    : is_debug_mode(false) {
  resize(num_cols, num_rows);
  place_mines(num_mines);
  update_num_adj_mines();
}

[[nodiscard]] auto Board::at(const size_t x, const size_t y)
    -> std::optional<std::reference_wrapper<Tile>> {
  if (x >= get_width() || y >= get_height()) {
    return {};
  }

  return tiles_[y][x];
}

void Board::try_reveal(const size_t x, const size_t y, const bool root_call) {
  auto tile_opt = at(x, y);
  if (!tile_opt) {
    return;
  }
  Tile &tile = *tile_opt;

  if (!tile.is_flagged && tile.is_mine && root_call) {
    state = State::LOSE;
    is_debug_mode = true;
    return;
  }

  if (tile.is_flagged || !tile.is_hidden || tile.is_mine) {
    return;
  }

  tile.is_hidden = false;

  if (tile.num_adj_mines) {
    return;
  }

  constexpr int RADIUS = 1;

  for (int offset_y = -RADIUS; offset_y <= RADIUS; offset_y++) {
    for (int offset_x = -RADIUS; offset_x <= RADIUS; offset_x++) {
      try_reveal(x + offset_x, y + offset_y, false);
    }
  }
}

void Board::update_state() {
  bool is_win = true;

  for_tile([&](size_t, size_t, Tile &tile) {
    if (tile.is_hidden && !tile.is_mine) {
      is_win = false;
    }
  });

  if (is_win) {
    state = State::WIN;
    is_debug_mode = true;
    flag_all_mines();
  }
}

void Board::flag_all_mines() {
  for_tile([&](size_t, size_t, Tile &tile) {
    if (tile.is_mine) {
      tile.is_flagged = true;
    }
  });
}

void Board::for_tile(std::function<void(size_t, size_t, Tile &)> callback) {
  const size_t w = get_width(), h = get_height();

  for (size_t y = 0; y < h; y++) {
    for (size_t x = 0; x < w; x++) {
      callback(x, y, *at(x, y));
    }
  }
}

void Board::for_adj(const size_t x, const size_t y,
                    std::function<void(size_t, size_t, Tile &)> callback) {
  constexpr int RADIUS = 1;

  for (int offset_y = -RADIUS; offset_y <= RADIUS; offset_y++) {
    for (int offset_x = -RADIUS; offset_x <= RADIUS; offset_x++) {
      const size_t adj_x = x + offset_x, adj_y = y + offset_y;

      if (auto tile_opt = at(adj_x, adj_y)) {
        callback(adj_x, adj_y, tile_opt->get());
      }
    }
  }
}

void Board::resize(const size_t w, const size_t h) {
  tiles_.resize(h);
  for (auto &row : tiles_) {
    row.resize(w);
  }
}

void Board::update_num_adj_mines() {
  for_tile([&](size_t x, size_t y, Tile &tile) {
    tile.num_adj_mines = 0;

    for_adj(x, y, [&](size_t, size_t, Tile &adj_tile) {
      if (adj_tile.is_mine)
        tile.num_adj_mines++;
    });
  });
}

void Board::place_mines(const size_t num_mines) {
  const size_t w = get_width(), h = get_height();
  const size_t num_sq = w * h;
  std::vector<Tile> tiles_1d(num_sq);

  size_t mines_to_place = std::min(num_mines, num_sq);

  for (size_t i = 0; i < mines_to_place; i++) {
    tiles_1d[i].is_mine = true;
  }

  std::random_device rd;
  std::default_random_engine generator(rd());

  std::ranges::shuffle(tiles_1d, generator);

  for_tile([&](size_t x, size_t y, Tile &tile) { tile = tiles_1d[y * w + x]; });
}

} // namespace game::components