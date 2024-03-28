#include "Window.h"
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <string>

using std::string;

Window::Window()
{
   //ctr
}

Window::Window(const sf::Vector2u& window_size, const string& window_title)
{
    windowSize =window_size;
    windowTitle = window_title;
    state = GameState::Default;
    setup();
}

void Window::setup()
{
    if( (windowSize.x <= 1600) && (windowSize.y <=900) )
    {
        window.create( sf::VideoMode(windowSize.x, windowSize.y), windowTitle, sf::Style::Default);
    }
    else
    {
        window.create( sf::VideoMode(windowSize.x, windowSize.y), windowTitle, sf::Style::Default);
    }

    window.setFramerateLimit(60);
}

void Window::update()
{
    window.setKeyRepeatEnabled(false);
    sf::Event event;

    while(window.pollEvent(event))
    {
        switch(event.type)
        {
        case sf::Event::Closed:
            closed = true;
            break;

        case sf::Event::KeyPressed:

            if( (event.key.code == sf::Keyboard::Enter) && !(state==GameState::Pause))
            {
                state = GameState::Play;
            }
            if( event.key.code == sf::Keyboard::O)
            {
                   state = GameState::Play;
            }
            if (event.key.code == sf::Keyboard::Q)
            {
                closed = true;
            }

            if( state == GameState::Play)
            {
                if( event.key.code == sf::Keyboard::Left )
                {
                    playerObj.setPath(Direction::LEFT);
                    path = true;
                }
                if(event.key.code == sf::Keyboard::Right)
                {
                    playerObj.setPath(Direction::RIGHT);
                    path = true;
                }
                if( event.key.code == sf::Keyboard::Up )
                {
                    playerObj.setPath(Direction::UP);
                    path = true;
                }
                if(event.key.code == sf::Keyboard::Down)
                {
                    playerObj.setPath(Direction::DOWN);
                    path = true;
                }
                if( (event.key.code == sf::Keyboard::Space) && (!shoot) )
                {
                    shoot = true;
                }
                if( event.key.code == sf::Keyboard::P)
                {
                    state = GameState::Pause;
                }
                break;

            case sf::Event::EventType::KeyReleased:
                if( (event.key.code == sf::Keyboard::Left) || (event.key.code == sf::Keyboard::Right) || (event.key.code == sf::Keyboard::Up) || (event.key.code == sf::Keyboard::Down) )
                {
                    path = false;
                }
                if(event.key.code == sf::Keyboard::Space)
                {
                    shoot = false;
                }
                break;
            default:
                break;

            }
        }
    }
}

void Window::clearWindow()
{
    window.clear(sf::Color::Black);
}

void Window::draw(const sf::Drawable& object)
{
    window.draw(object);
}

void Window::display()
{
    window.display();
}

void Window::turnOffShoot()
{
    shoot = false;
}

sf::Vector2u Window::getWindowSize() const
{
    return windowSize;
}

bool Window::isClosed() const
{
    return closed;
}

Direction Window::getMovement() const
{
    return playerObj.getDirection();
};

bool Window::getShoot() const
{
    return shoot;
};

GameState Window::isPlaying() const
{
    return state;
}

bool Window::getPath() const
{
    return path;
}

void Window:: setGameOver()
{
    state = GameState::End;
}

void Window:: setToDefault()
{
    state = GameState::Default;
}
