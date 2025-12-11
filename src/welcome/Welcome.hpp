#pragma once

#include "../config/Config.hpp"
#include "components/TextManager.hpp"
#include <SFML/Graphics.hpp>
#include <optional>
#include <string>

namespace welcome {

class Welcome : private components::TextManager {
public:
  Welcome(const config::Config &config, sf::RenderWindow &window)
      : user_name_(""), window_(window),
        components::TextManager(config, window.getSize()) {}
  auto run() -> bool;
  auto get_user_name() -> std::string { return user_name_; }

private:
  void update_user_name(const sf::Uint32 next_c,
                        const size_t max_input_size = 10);
  void draw();

  std::string user_name_;
  sf::RenderWindow &window_;
};

} // namespace welcome
