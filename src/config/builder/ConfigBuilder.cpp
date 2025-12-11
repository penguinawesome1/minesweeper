#include "ConfigBuilder.hpp"
#include <filesystem>
#include <fstream>
#include <iostream>
#include <utility>

namespace fs = std::filesystem;

namespace config::builder {

[[nodiscard]] auto ConfigBuilder::set_counts_from(const std::string &path)
    -> ConfigBuilder & {
  std::ifstream in(path);

  if (!in) {
    std::cerr << "Failed to open path: " << path << "\n";
    return *this;
  }

  in >> num_cols_ >> num_rows_ >> num_mines_;

  if (in.fail()) {
    std::cerr << "Failed to read counts from path: " << path << "\n";
  }

  return *this;
}

[[nodiscard]] auto ConfigBuilder::add_image_paths_from(const std::string &path)
    -> ConfigBuilder & {
  for (const auto &entry : fs::directory_iterator(path)) {
    image_paths_[entry.path().stem().string()] = entry.path().string();
  }

  return *this;
}

[[nodiscard]] auto ConfigBuilder::build() -> const Config {
  return {num_cols_,
          num_rows_,
          num_mines_,
          sq_length_,
          std::move(font_path_),
          std::move(leaderboard_path_),
          std::move(image_paths_)};
}

} // namespace config::builder