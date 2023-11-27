#include "Entity.h"

void Entity::set_velocity(sf::Vector2f v)
{
    velocity = v;
}
    

void Entity::set_velocity(float vx, float vy)
{
    velocity.x = vx;
    velocity.y = vy;
}

sf::Vector2f Entity::get_velocity() const
{
    return velocity;
}
