#include "Game.hpp"

Game::Game()
    : mWindow(sf::VideoMode(1600, 900), "SFML Application", sf::Style::Titlebar | sf::Style::Close)
{
    mFont.loadFromFile("resources/fonts/arial.ttf");
    mWindow.setVerticalSyncEnabled(true);
    // to the refresh rate of the monitor, usually around 60Hz. This can avoid graphical artifacts such as screen tearing
    mWindow.setPosition(sf::Vector2i(200, 50));
}

void Game::run()
{
    float dt = 1.f / 60.f;
    float timeSinceLastUpdate = 0.f;
    sf::Clock clock;
    Screen mScreen(mWindow, mFont);

    while (mWindow.isOpen())
    {
        float dt = clock.restart().asSeconds();
        processEvents(mScreen, dt);
        mWindow.clear(sf::Color::White);
        mScreen.draw(dt);
        mWindow.display();
    }
    /* while (mWindow.isOpen())
    {
        processEvents();
        timeSinceLastUpdate += clock.restart().asSeconds();
        while (timeSinceLastUpdate > dt)
        {
            timeSinceLastUpdate -= dt;
            processEvents();
            // handle(screen, dt);
        }
        mWindow.clear(sf::Color::White);
        // mStaticArray.draw();
        mScreen.draw();
        mWindow.display();
        // render(screen);
    } */
}

void Game::processEvents(Screen &mScreen, float dt)
{
    sf::Event event;
    while (mWindow.pollEvent(event))
    {
        switch (event.type)
        {
        case sf::Event::Closed:
            mWindow.close();
            break;
        default:
            mScreen.handle(event, dt);
            break;
        }
    }
    sf::Event noEvent;
    mScreen.handle(noEvent, dt);
}
