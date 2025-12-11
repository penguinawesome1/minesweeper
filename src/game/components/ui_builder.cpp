#pragma once

#include "ui_builder.hpp"

namespace game::components {

[[nodiscard]] auto
get_happy_face_button(const config::Config &config,
                      const managers::AssetManager &asset_manager)
    -> sf::Sprite {
  sf::Sprite sprite;
  sprite.setTexture(*asset_manager.get_texture("face_happy"));
  sprite.setPosition(config.num_cols * config.sq_length * 0.5 - 32.0,
                     (config.num_rows + 0.5) * config.sq_length);
  return sprite;
}

[[nodiscard]] auto get_debug_button(const config::Config &config,
                                    const managers::AssetManager &asset_manager)
    -> sf::Sprite {
  sf::Sprite sprite;
  sprite.setTexture(*asset_manager.get_texture("debug"));
  sprite.setPosition(config.num_cols * config.sq_length - 304.0,
                     (config.num_rows + 0.5) * config.sq_length);
  return sprite;
}

[[nodiscard]] auto get_pause_button(const config::Config &config,
                                    const managers::AssetManager &asset_manager)
    -> sf::Sprite {
  sf::Sprite sprite;
  sprite.setTexture(*asset_manager.get_texture("pause"));
  sprite.setPosition(config.num_cols * config.sq_length - 240.0,
                     (config.num_rows + 0.5) * config.sq_length);
  return sprite;
}

[[nodiscard]] auto
get_leaderboard_button(const config::Config &config,
                       const managers::AssetManager &asset_manager)
    -> sf::Sprite {
  sf::Sprite sprite;
  sprite.setTexture(*asset_manager.get_texture("leaderboard"));
  sprite.setPosition(config.num_cols * config.sq_length - 176.0,
                     (config.num_rows + 0.5) * config.sq_length);
  return sprite;
}

[[nodiscard]] auto
get_counter_digit(const config::Config &config,
                  const managers::AssetManager &asset_manager, const int index,
                  const int shift) -> sf::Sprite {
  sf::Sprite sprite;
  sprite.setTexture(*asset_manager.get_texture("digits"));
  sprite.setTextureRect(sf::IntRect(shift * 21, 0, 21, 32));
  sprite.setPosition(12 + 21 * index, (config.num_rows + 0.5) * 32 + 16);
  return sprite;
}

[[nodiscard]] auto get_timer_digit(const config::Config &config,
                                   const managers::AssetManager &asset_manager,
                                   const int index, const int shift)
    -> sf::Sprite {
  sf::Sprite sprite;
  sprite.setTexture(*asset_manager.get_texture("digits"));
  sprite.setTextureRect(sf::IntRect(shift * 21, 0, 21, 32));
  sprite.setPosition(config.num_cols * 32 - 97 + 21 * index,
                     (config.num_rows + 0.5) * 32 + 16);
  return sprite;
}

} // namespace game::components