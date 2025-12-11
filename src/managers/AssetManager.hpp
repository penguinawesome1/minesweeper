#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>
#include <optional>
#include <unordered_map>

namespace managers {

class AssetManager {
public:
  AssetManager(const std::unordered_map<std::string, std::string> &paths);

  /**
   * # Source
   *
   * https://stackoverflow.com/questions/34512437/simplest-method-to-check-whether-unordered-map-of-unordered-maps-contains-key
   */
  [[nodiscard]] auto get_texture(const std::string &key) const
      -> std::optional<std::reference_wrapper<const sf::Texture>>;

private:
  std::unordered_map<std::string, sf::Texture> textures_;
  sf::Font font_;
};

} // namespace managers
