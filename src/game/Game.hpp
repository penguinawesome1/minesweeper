#pragma once

#include "components/Board.hpp"
#include "components/Buttons.hpp"
#include "components/FlagManager.hpp"
#include "components/TimerManager.hpp"
#include <SFML/Graphics.hpp>
#include <array>
#include <optional>

namespace game {

class Game {
public:
  Game(const config::Config &config, sf::RenderWindow &window,
       std::string name);
  void run();
  void try_handle_input(const sf::Event event);
  void draw();
  void reset();
  void pause();
  void unpause();
  void handle_win();

  auto get_pause() -> bool { return is_paused_; }
  void toggle_pause() { is_paused_ ? unpause() : pause(); }

  auto get_updated_leaderboard_pos() -> std::optional<size_t> {
    return updated_leaderboard_pos_;
  }

private:
  managers::AssetManager asset_manager_;
  components::Board board_;
  components::TimerManager timer_manager_;
  components::FlagManager flag_manager_;
  components::Buttons buttons_;
  const config::Config &config_;
  bool is_paused_;
  sf::RenderWindow &window_;
  std::string name_;
  std::optional<size_t> updated_leaderboard_pos_;
};

} // namespace game