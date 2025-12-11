#pragma once

#include "../Config.hpp"
#include <string>
#include <unordered_map>

namespace config::builder {

class ConfigBuilder {
public:
  [[nodiscard]] auto set_sq_length(const size_t l) -> ConfigBuilder & {
    sq_length_ = l;
    return *this;
  }

  [[nodiscard]] auto set_font_path(std::string p) -> ConfigBuilder & {
    font_path_ = std::move(p);
    return *this;
  }

  [[nodiscard]] auto set_leaderboard_path(std::string p) -> ConfigBuilder & {
    leaderboard_path_ = std::move(p);
    return *this;
  }

  [[nodiscard]] auto set_counts_from(const std::string &path)
      -> ConfigBuilder &;

  /**
   * # Source
   *
   * https://stackoverflow.com/questions/612097/how-can-i-get-the-list-of-files-in-a-directory-using-c-or-c
   * https://stackoverflow.com/questions/69293016/not-understanding-stdfilesystemdirectory-iterator
   */
  [[nodiscard]] auto add_image_paths_from(const std::string &path)
      -> ConfigBuilder &;

  [[nodiscard]] auto build() -> const Config;

private:
  size_t num_cols_ = 25, num_rows_ = 16, num_mines_ = 50, sq_length_ = 32;
  std::string font_path_, leaderboard_path_;
  std::unordered_map<std::string, std::string> image_paths_;
};

} // namespace config::builder