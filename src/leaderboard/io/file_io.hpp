#pragma once

#include <optional>
#include <string>
#include <vector>

namespace leaderboard::io {

struct LeaderboardPair {
  std::string time, name;
};

[[nodiscard]] auto get_leaderboard_info(const std::string &path)
    -> std::vector<LeaderboardPair>;

/**
 * # Source
 *
 * https://stackoverflow.com/questions/17032970/clear-data-inside-text-file-in-c
 */
void set_leaderboard_info(const std::string &path,
                          const std::vector<LeaderboardPair> &info);

auto update_leaderboard(const std::string &path, std::string name,
                        std::string time) -> std::optional<size_t>;

} // namespace leaderboard::io