#include "game.hpp"

Game::Game()
: mWindow(sf::VideoMode(1600, 900), "SFML Application")
, mPlayer()
{
    mFont.loadFromFile("resources/fonts/arial.ttf");
    mWindow.setVerticalSyncEnabled(true);
    // to the refresh rate of the monitor, usually around 60Hz. This can avoid graphical artifacts such as screen tearing

    mWindow.setPosition(sf::Vector2i(10, 10)); 
    mPlayer.setRadius(40.f);
    mPlayer.setPosition(100.f, 100.f);
    mPlayer.setFillColor(sf::Color::Cyan);

    TimePerFrame = sf::seconds(1.f / 60.f);
    mIsMovingUp = mIsMovingDown = mIsMovingLeft = mIsMovingRight = false;
    PlayerSpeed = 100.f;
}

void Game::run()
{
    // sf::Clock clock;
    // sf::Time timeSinceLastUpdate = sf::Time::Zero;
    // while (mWindow.isOpen())
    // {
    //     processEvents();
    //     timeSinceLastUpdate += clock.restart();
    //     while (timeSinceLastUpdate > TimePerFrame)
    //     {
    //         timeSinceLastUpdate -= TimePerFrame;
    //         processEvents();
    //         update(TimePerFrame); 
    //     }
    //     render();
    // }
    
    /*
    // Create button
    Button button(mWindow, sf::Vector2f(200, 50), sf::Vector2f(300, 250), sf::Color::Cyan, sf::Color::Magenta, "Click me!", font, 25);

    while (mWindow.isOpen())
    {
        sf::Event event;
        while (mWindow.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                mWindow.close();
            }

            // Check if mouse is hovering over button
            if (button.isMouseOver())
            {
                button.setHovered(true);

                // Check if mouse is clicked on button
                if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left)
                {
                    // Do something when button is clicked
                    // ...
                }
            }
            else
            {
                button.setHovered(false);
            }
        }

        mWindow.clear(sf::Color::White);

        // Draw button
        button.draw();

        mWindow.display();
    }
    */

    sf::Clock clock;
    sf::Time timeSinceLastUpdate = sf::Time::Zero;
    Screen screen(mWindow, mFont);
    while (mWindow.isOpen())
    {
        processEvents();
        timeSinceLastUpdate += clock.restart();
        while (timeSinceLastUpdate > TimePerFrame)
        {
            timeSinceLastUpdate -= TimePerFrame;
            processEvents();
            screen.setHovered();
            // update(TimePerFrame); 
        }
        // render();
        mWindow.clear(sf::Color::White);

        // Draw button
        screen.draw();

        mWindow.display();
    }

}

void Game::handlePlayerInput(sf::Keyboard::Key key, bool isPressed)
{
    if (key == sf::Keyboard::W)
        mIsMovingUp = isPressed;
    else if (key == sf::Keyboard::S)
        mIsMovingDown = isPressed;
    else if (key == sf::Keyboard::A)
        mIsMovingLeft = isPressed;
    else if (key == sf::Keyboard::D)
        mIsMovingRight = isPressed;
}

void Game::processEvents()
{
    sf::Event event;
    while (mWindow.pollEvent(event))
    {
        switch (event.type)
        {
            // case sf::Event::KeyPressed:
            //     handlePlayerInput(event.key.code, true);
            //     break;
            // case sf::Event::KeyReleased:
            //     handlePlayerInput(event.key.code, false);
            //     break;
            case sf::Event::Closed:
                mWindow.close();
                break;
            default:
                break;
        }
    }
}

void Game::update(sf::Time deltaTime)
{
    sf::Vector2f movement(0.f, 0.f);
    if (mIsMovingUp) // Oy positive downward
        movement.y -= PlayerSpeed;
    if (mIsMovingDown)
        movement.y += PlayerSpeed;
    if (mIsMovingLeft)
        movement.x -= PlayerSpeed;
    if (mIsMovingRight)
        movement.x += PlayerSpeed;

    mPlayer.move(movement * deltaTime.asSeconds());
}

void Game::render()
{
    mWindow.clear(sf::Color::White);
    mWindow.draw(mPlayer); // sf::RenderWindow::draw() method
    mWindow.display();
}