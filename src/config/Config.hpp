#pragma once

#include <string>
#include <unordered_map>

namespace config {

struct Config {
  const size_t num_cols, num_rows, num_mines, sq_length;
  const std::string font_path, leaderboard_path;
  const std::unordered_map<std::string, std::string> image_paths;
};

} // namespace config