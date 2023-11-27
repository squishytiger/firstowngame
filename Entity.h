#ifndef Entity_h
#define Entity_h

class Entity_h {
    public:
        void set_velocity(sf::Vector2f velocity);
        void set_velocity(float velocity_x, float velocity_y);
        sf::Vector2f get_velocity() const;

    private:
        sf::Vector2f velocity;
};

#endif
