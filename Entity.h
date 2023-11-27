#ifndef Entity_h
#define Entity_h

#include <SFML/Graphics.hpp>

class Entity {
    public:
        void set_velocity(sf::Vector2f v);
        void set_velocity(float vx, float vy);
        sf::Vector2f get_velocity() const;

    private:
        sf::Vector2f velocity;
};

#endif
