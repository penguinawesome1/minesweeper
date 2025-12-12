#include "config/Config.hpp"
#include "config/builder/ConfigBuilder.hpp"
#include "game/Game.hpp"
#include "welcome/Welcome.hpp"
#include <SFML/Graphics.hpp>

auto main() -> int {
  const config::Config config =
      config::builder::ConfigBuilder()
          .set_counts_from("../files/config.cfg")
          .set_font_path("../files/font.ttf")
          .set_leaderboard_path("../files/leaderboard.txt")
          .add_image_paths_from("../files/images")
          .set_sq_length(32)
          .build();

  sf::RenderWindow window(
      sf::VideoMode(config.num_cols * config.sq_length,
                    config.num_rows * config.sq_length + 100),
      "Minesweeper", sf::Style::Close);

  welcome::Welcome welcome = welcome::Welcome(config, window);
  if (!welcome.run()) {
    return 0;
  }

  game::Game game = game::Game(config, window, welcome.get_user_name());
  game.run();

  return 0;
}
