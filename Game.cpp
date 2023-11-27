#include "Game.h"

const float Game::player_speed = 500.f;
const sf::Time Game::time_per_frame = sf::seconds(1.f / 100.f);

Game::Game():
    window(sf::VideoMode(640, 480), "first own game"),
    player(),
    background(),
    moving_up(false),
    moving_down(false),
    moving_right(false),
    moving_left(false)
{
    textures.load(Texture_id::Background, "media/textures/background.jpeg");
    textures.load(Texture_id::Player, "media/textures/player.png");

    background.setTexture(textures.get(Texture_id::Background));
    background.setPosition(0.f, 0.f);

    player.setTexture(textures.get(Texture_id::Player));
    player.setPosition(100.f, 100.f);
}


void Game::run()
{
    sf::Clock clock;
    sf::Time time_since_last_update = sf::Time::Zero;
    while (window.isOpen()) {
        sf::Time time_elapsed = clock.restart();
        time_since_last_update += time_elapsed;
        while (time_since_last_update > time_per_frame) {
            time_since_last_update -= time_per_frame;

            process_events();
            update(time_per_frame);
        }
        render();
    }
}

void Game::process_events()
{
    sf::Event event;
    while (window.pollEvent(event)) {
        switch (event.type) {
            case sf::Event::Closed:
                window.close();
                break;
            case sf::Event::KeyPressed:
                handle_key_pressed_released(event.key.code, true);
                break;
            case sf::Event::KeyReleased:
                handle_key_pressed_released(event.key.code, false);
                break;
            default:
                break;
        }
    }
}

void Game::update(sf::Time time_elapsed)
{
    sf::Vector2f movement(0.f, 0.f);
    
    if (moving_up)
        movement.y -= player_speed;
    if (moving_down)
        movement.y += player_speed;
    if (moving_right)
        movement.x += player_speed;
    if (moving_left)
        movement.x -= player_speed;

    player.move(movement * time_elapsed.asSeconds());
}

void Game::render()
{
    window.clear();
    window.draw(background);
    window.draw(player);
    window.display();
}

void Game::handle_key_pressed_released(sf::Keyboard::Key key, bool pressed)
{
    switch (key) {
        case sf::Keyboard::Up:
            moving_up = pressed;
            break;
        case sf::Keyboard::Down:
            moving_down = pressed;
            break;
        case sf::Keyboard::Right:
            moving_right = pressed;
            break;
        case sf::Keyboard::Left:
            moving_left = pressed;
            break;
        case sf::Keyboard::Q:
            window.close();
            break;
        default:
            break;
    }
}
