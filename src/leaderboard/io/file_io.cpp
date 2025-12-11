#include "file_io.hpp"
#include <fstream>
#include <iostream>

namespace leaderboard::io {

[[nodiscard]] auto get_leaderboard_info(const std::string &path)
    -> std::vector<LeaderboardPair> {
  std::vector<LeaderboardPair> pairs;
  std::ifstream in(path);
  std::string line;

  if (!in) {
    std::cerr << "Failed to open path: " << path << "\n";
    return pairs;
  }

  while (std::getline(in, line)) {
    const size_t comma_pos = line.find(",");
    pairs.push_back({.time = line.substr(0, comma_pos),
                     .name = line.substr(comma_pos + 1)});
  }

  return pairs;
}

void set_leaderboard_info(const std::string &path,
                          const std::vector<LeaderboardPair> &pairs) {
  const size_t pairs_size = pairs.size();
  std::ofstream out;
  out.open(path, std::ofstream::out | std::ofstream::trunc);

  for (size_t i = 0; i < pairs_size; i++) {
    out << pairs[i].time << "," << pairs[i].name << "\n";
  }
}

auto update_leaderboard(const std::string &path, std::string name,
                        std::string time) -> std::optional<size_t> {
  auto pairs = get_leaderboard_info(path);
  const size_t pairs_size = pairs.size();

  for (size_t i = 0; i < 5; i++) {
    if (i < pairs_size && time >= pairs[i].time)
      continue;

    pairs.insert(pairs.begin() + i, {std::move(time), std::move(name)});
    while (pairs.size() > 5) {
      pairs.pop_back();
    }
    set_leaderboard_info(path, pairs);

    return i;
  }

  return {};
}

} // namespace leaderboard::io