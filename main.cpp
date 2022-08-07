
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <iostream>
#include "Player.h"
#include "Collision.h"
#include "Refree.h"
#include "Timer.h"
#include "Initial.h"
using namespace sf;

int main(int argc, char** argv)
{   
    
    if (Initial::showMainMenu() == 1)
    {
        sf::RenderWindow window(sf::VideoMode(1366, 704), "Duel");
        // window.setVerticalSyncEnabled(true);
        //window.setFramerateLimit(60);

        sf::Vector2u wsize = window.getSize();
        std::cout << "Width " << wsize.x << "Height " << wsize.y;

        sf::Texture grid;
        if (!grid.loadFromFile("japan.gif"))
        {
            std::cout << "error for texture load";
            return -1;
        }
        sf::Sprite gridsprite(grid);
        gridsprite.setScale(1.7075f, 2.095f);
        sf::Vector2u size = grid.getSize();

        gridsprite.setOrigin(size.x / 2, size.y / 2);
        gridsprite.setPosition(window.getSize().x / 2, window.getSize().y / 2);

        //FIghter 

        sf::Texture tplayer1;  //this is to import the player animation
        if (!tplayer1.loadFromFile("ryu.png"))
        {
            std::cout << "error for texture load player";
            return -2;
        }
        tplayer1.setRepeated(true);
        //tplayer.setSmooth(true); //this is to blur the sprite to make it smooth.

        //PLayer.cpp//Player.h
        Player player1(&tplayer1, sf::Vector2u(16, 10), 98.0f, true); //player1 vanne object create garyom.


        sf::Texture tplayer2;
        if (!tplayer2.loadFromFile("ken.png"))
        {
            std::cout << "error for texture load player";
            return -2;
        }
        tplayer2.setRepeated(true);

        //PLayer.cpp//Player.h
        Player player2(&tplayer2, sf::Vector2u(16, 10), 98.0f, false);

        float deltaTime = 0.f; //this is the difference in time to switch between frames
        sf::Clock clock;
        sf::Clock clockForRoundTime;


        //For Font for Timer
        sf::Font font;
        if (!font.loadFromFile("calibri.ttf"))
        {
            std::cout << "Calibri ttf";
            return -1;
        }

        Timer timer90sec(font, clockForRoundTime.getElapsedTime().asSeconds());
        window.setKeyRepeatEnabled(false);
        //game loop starts now


        //For Refree;

        Refree refree(500.0f, 500.0f);
        float totaltime{};
        while (window.isOpen())
        {
            timer90sec.update(static_cast<int>(clockForRoundTime.getElapsedTime().asSeconds()));
            deltaTime = clock.restart().asSeconds();
            // std::cout << deltaTime<<std::endl;
            sf::Event event;


            while (window.pollEvent(event))
            {
                if (event.type == sf::Event::Closed || (clockForRoundTime.getElapsedTime().asSeconds()>90))
                {
                    window.close();
                }

            }


            player1.Update(deltaTime, wsize, true, Collision::checkCollision(player1.playerPosition(), player2.playerPosition()));
            player2.Update(deltaTime, wsize, false, Collision::checkCollision(player1.playerPosition(), player2.playerPosition()));

            totaltime += deltaTime;
            if (Collision::checkCollision(player1.playerPosition(), player2.playerPosition())
                && totaltime >= 0.15
                && (player1.isFacingRIght() == true && player2.isFacingRIght() == false))
            {
                totaltime = 0;
                refree.mediate(player1.player_state, player2.player_state);
            }

            player1.currentHealth(refree.getP1Health());
            player2.currentHealth(refree.getP2Health());


            window.clear();
            window.draw(gridsprite);
            timer90sec.Draw(window);
            player1.Draw(window);
            player2.Draw(window);
            window.display();

        }
    }
    return 0;
}