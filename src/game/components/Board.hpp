#pragma once

#include "../../config/Config.hpp"
#include <functional>
#include <optional>
#include <random>
#include <vector>

namespace game::components {

class Board {
public:
  struct Tile {
    bool is_hidden = true, is_mine = false, is_flagged = false;
    size_t num_adj_mines = 0;
  };

  enum class State { IN_PROGRESS, WIN, LOSE } state = State::IN_PROGRESS;

  Board(const size_t num_rows, const size_t num_cols, const size_t num_mines);

  [[nodiscard]] auto get_height() const -> size_t { return tiles_.size(); }
  [[nodiscard]] auto get_width() const -> size_t {
    return get_height() > 0 ? tiles_[0].size() : 0;
  }
  [[nodiscard]] auto at(const size_t x, const size_t y)
      -> std::optional<std::reference_wrapper<Tile>>;

  void try_reveal(const size_t x, const size_t y, const bool root_call = true);
  void update_state();
  void for_tile(std::function<void(size_t, size_t, Tile &)> callback);
  void for_adj(const size_t x, const size_t y,
               std::function<void(size_t, size_t, Tile &)> callback);

  bool is_debug_mode;

private:
  void resize(const size_t w, const size_t h);
  void flag_all_mines();
  void update_num_adj_mines();

  /**
   * Place the allotted number of mines spread randomly throughout the
   * board.
   *
   * If the number of mines exceeds the size of the board it will fill every
   * square.
   *
   * # Source
   *
   * https://stackoverflow.com/questions/6926433/how-to-shuffle-a-stdvector
   * https://stackoverflow.com/questions/22907473/c-default-random-engine-creates-all-the-time-same-series-of-numbers
   */
  void place_mines(const size_t num_mines);

  std::vector<std::vector<Tile>> tiles_;
  size_t sq_length_;
};

} // namespace game::components