#pragma once

#include "../Game.hpp"
#include "../components/Board.hpp"
#include "../components/Buttons.hpp"
#include "../components/FlagManager.hpp"

#include <SFML/Graphics.hpp>

namespace game::helpers {

struct ClickParams {
  components::Board &board;
  const config::Config &config;
  const sf::Window &window;
  const bool is_paused;
  const components::Buttons &buttons;
  components::FlagManager &flag_manager;
  Game &game;
};

void handle_left_click(ClickParams &params);

void handle_right_click(ClickParams &params);

} // namespace game::helpers
