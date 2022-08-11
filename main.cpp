
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

        //Hit Spark
        sf::Texture spark;
        if(!spark.loadFromFile("blue_hit.png"))
        {
            std::cout<<"Error for spark image";
            return -1;
        }
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
        Player player1(&tplayer1, sf::Vector2u(16, 10), 150.0f, true, &spark); //player1 vanne object create garyom.


        sf::Texture tplayer2;
        if (!tplayer2.loadFromFile("ken.png"))
        {
            std::cout << "error for texture load player";
            return -2;
        }
        tplayer2.setRepeated(true);

        //PLayer.cpp//Player.h
        Player player2(&tplayer2, sf::Vector2u(16, 10), 98.0f, false, &spark);

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
            float p1_health = refree.getP1Health();
            float p2_health = refree.getP2Health();

            if  (Collision::checkCollision(player1.playerPosition(), player2.playerPosition())
                && (player1.isTransitionPhase() || player2.isTransitionPhase())
                && (player1.isFacingRIght() == true || player2.isFacingRIght() == false)
                ) 
            {
                // totaltime = 0;
                refree.mediate(player1.player_state, player2.player_state, player1.isImpactPhase(), player2.isImpactPhase());
            }

            //Health update part
            player1.currentHealth(refree.getP1Health());
            player2.currentHealth(refree.getP2Health());

            //if health changes then state of player must be that of reacting to the hit
            if(p1_health > refree.getP1Health())
            {
                player1.player_state = refree.getNewState_p1();
            }
            if(p2_health > refree.getP2Health())
            {
                player2.player_state = refree.getNewState_p2();
            }

            //spark part
            //this is remnants of the part to tell you that anything that must be drawn should be after window.clear
            //also draw priortiy wise 1st background then on and on
            


            if(refree.getP1Health() <0 ||refree.getP2Health() <0)   
                window.close();
            
            window.clear();
            window.draw(gridsprite);
            timer90sec.Draw(window);
            player1.Draw(window);
            player2.Draw(window);
            if(refree.getP1_impact() && player1.isImpactPhase())
            {
                player1.ImpactForce::Draw(window);
            }
            if(refree.getP2_impact() && player2.isImpactPhase())
            {
                player2.ImpactForce::Draw(window);
            }
            
            window.display();

        }
    }
    return 0;
}