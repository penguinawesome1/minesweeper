#include "AssetManager.hpp"

namespace managers {

AssetManager::AssetManager(
    const std::unordered_map<std::string, std::string> &paths) {
  for (const auto &[k, v] : paths) {
    sf::Texture texture;

    if (!texture.loadFromFile(v)) {
      std::cerr << "Failed to load texture from path: " << v << "\n";
      continue;
    }

    textures_[k] = texture;
  }
}

[[nodiscard]] auto AssetManager::get_texture(const std::string &key) const
    -> std::optional<std::reference_wrapper<const sf::Texture>> {
  auto it = textures_.find(key);

  if (it == textures_.end()) {
    return {};
  }

  return it->second;
}

} // namespace managers
