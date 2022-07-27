
#include <SFML/Graphics.hpp>
#include <iostream>
#include "Player.h"
#include "Collision.h"

int main(int argc, char** argv)
{

    sf::RenderWindow window(sf::VideoMode(1366, 704), "Hello World");
    window.setVerticalSyncEnabled(true);
    //window.setFramerateLimit(60);

    sf::Vector2u wsize = window.getSize();
    std::cout << "Width " << wsize.x << "Height " << wsize.y;

    sf::Texture grid;
    if (!grid.loadFromFile("grid.jpg"))
    {
        std::cout << "error for texture load";
        return -1;
    }
    sf::Sprite gridsprite(grid);
    sf::Vector2u size = grid.getSize();

    gridsprite.setOrigin(size.x / 2, size.y / 2);
    gridsprite.setPosition(window.getSize().x / 2, window.getSize().y / 2);

    //FIghter 

    sf::Texture tplayer;  //this is to import the player animation
    if (!tplayer.loadFromFile("idle_punch_walking_fixed.png"))
    {
        std::cout << "error for texture load player";
        return -2;
    }
    tplayer.setRepeated(true); 
    //tplayer.setSmooth(true); //this is to blur the sprite to make it smooth.

    //PLayer.cpp//Player.h
    Player player(&tplayer, sf::Vector2u(13, 3), 0.15f, 98.0f, true); //player1 vanne object create garyom.


    sf::Texture tplayer2;
    if (!tplayer2.loadFromFile("idle_punch_walking_fixed.png"))
    {
        std::cout << "error for texture load player";
        return -2;
    }
    tplayer2.setRepeated(true);


    //PLayer.cpp//Player.h
    Player player2(&tplayer2, sf::Vector2u(13, 3), 0.15f, 98.0f, false);

    float deltaTime = 0.f; //this is the difference in time to switch between frames
    sf::Clock clock;

    //game loop starts now
    while (window.isOpen())
    {
        deltaTime = clock.restart().asSeconds();
        sf::Event event;


        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }

        }


        player.Update(deltaTime, wsize, true,Collision::checkCollision(player.playerPosition(),player2.playerPosition()));
        player2.Update(deltaTime, wsize, false, Collision::checkCollision(player.playerPosition(), player2.playerPosition()));

        window.clear();
        window.draw(gridsprite);
        player.Draw(window);
        player2.Draw(window);
        window.display();


    }
    return 0;
}