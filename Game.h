#ifndef Game_h_guard
#define Game_h_guard

#include <SFML/Graphics.hpp>
#include "Resource_holder.h"

enum class Texture_id {
    Player,
    Background,
};

class Game {
    public:
        Game();
        void run();

    private:
        void process_events();
        void update(sf::Time time_elapsed);
        void render();
        void handle_key_pressed_released(sf::Keyboard::Key  key, bool pressed);

        sf::RenderWindow window;
        sf::Sprite player;
        sf::Sprite background;

        bool moving_up;
        bool moving_down;
        bool moving_right;
        bool moving_left;

        Resource_holder<Texture_id, sf::Texture> textures;

        static const float player_speed;
        static const sf::Time time_per_frame;
};

#endif
