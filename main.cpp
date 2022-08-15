
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include "Player.h"
#include "Collision.h"
#include "Refree.h"
#include "Timer.h"
#include "Impact_force.h"
#include "Initial.h"



using namespace sf;

int main(int argc, char** argv)
{   int state_of_main_menu{};
    do
    {    
        state_of_main_menu = Initial::showMainMenu();
        if ( state_of_main_menu == 1)
        {
        
            sf::RenderWindow window(sf::VideoMode(1366, 704), "Duel");
            // window.setVerticalSyncEnabled(true);
            window.setFramerateLimit(60);

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
            spark.setRepeated(true);
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
            

            //SOUND - SOUND
            sf::Music music;
            if(!music.openFromFile("music.wav"));
            {
                std::cout<<"error for background_music.wav opening";
                // return -2;s// program should terminate but terminates even though open for file is successful
            }
            music.setVolume(30.0f);
            music.setLoop(true);
            music.play();


            //KICK SOUND
            sf::SoundBuffer kick_soundBuffer;
            if(!kick_soundBuffer.loadFromFile("Kick.ogg"))
            {
                std::cout << "Kick audio file problem";
                return -2;
            }
            sf::Sound kick_sound;
            kick_sound.setBuffer(kick_soundBuffer);
            // kick_sound.setLoop(true);


            //PUNCH SOUND
            sf::SoundBuffer punch_soundBuffer;
            if(!punch_soundBuffer.loadFromFile("Punch.ogg"))
            {
                std::cout << "Punch.ogg audio file problem";
                return -2;
            }
            sf::Sound punch_sound;
            punch_sound.setBuffer(punch_soundBuffer);
            punch_sound.setPlayingOffset(sf::seconds(0.5f));


            //MATCH END SOUND
            sf::SoundBuffer end_soundBuffer;
            if(!end_soundBuffer.loadFromFile("End.ogg"))
            {
                std::cout << "End.ogg audio file probtttttttlem";
                return -2;
            }
            sf::Sound end_sound;
            end_sound.setBuffer(end_soundBuffer);
        


            Timer timer90sec(font, clockForRoundTime.getElapsedTime().asSeconds());
            window.setKeyRepeatEnabled(false);


            //For Refree;

            Refree refree(500.0f, 500.0f);

            //these following variables are for spark animaton
            float totaltime{};
            int spark_count_p1{0};
            int spark_count_p2{0};
            
            //game loop starts now

            while (window.isOpen())
            {
                timer90sec.update(static_cast<int>(clockForRoundTime.getElapsedTime().asSeconds()));
                deltaTime = clock.restart().asSeconds();

                if(clockForRoundTime.getElapsedTime().asSeconds()  < 2)
                    end_sound.play();

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

                
                float p1_health = refree.getP1Health();
                float p2_health = refree.getP2Health();

                if  (Collision::checkCollision(player1.playerPosition(), player2.playerPosition())
                    && (player1.isTransitionPhase() || player2.isTransitionPhase())
                    && ((player1.isFacingRight() == true||player1.isFacingRight() == false ) && player2.isFacingRight() == false) 
                    ) 
                {
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
                

                
                window.clear();
                window.draw(gridsprite);
                timer90sec.Draw(window);
                player1.Draw(window);
                player2.Draw(window);

                //Following part checks if hit spark is to be shown or not (if there is an object to punch it shows)
                totaltime += deltaTime;
                
                if(refree.getP1_impact() && player1.isImpactPhase())
                {
                    if(totaltime >= 0.1)
                    {
                        spark_count_p1++;
                        player1.ImpactForce::Update(spark_count_p1);
                        totaltime =0;
                    }
                    player1.ImpactForce::Draw(window);
                    
                    if(spark_count_p1 > 3)
                    {
                        refree.setP1_impact(false);
                        spark_count_p1 = 0;
                        //  kick_sound.stop();
                    }
                    if(player1.player_state == PlayerState::KICK)
                        kick_sound.play();
                    else if (player1.player_state == PlayerState::PUNCH)
                        punch_sound.play();
                }


                //FOR PLAYER2 SPARK
                else if(refree.getP2_impact() && player2.isImpactPhase())
                {
                    if(totaltime >= 0.1)
                    {
                        spark_count_p2++;
                        player2.ImpactForce::Update(spark_count_p2);
                        totaltime = 0;
                    }
                    player2.ImpactForce::Draw(window);
                    
                    if(spark_count_p2 > 3)
                    {
                        refree.setP2_impact(false);
                        spark_count_p2 = 0;
                    }

                    if(player2.player_state == PlayerState::KICK)
                        kick_sound.play();
                    else if (player2.player_state == PlayerState::PUNCH)
                        punch_sound.play();
                    
                }

                window.display();
                //HERE YOU CAN CALL THE CASE FOR WHEN HEALTH IS ZERO
                if(refree.getP1Health() <0 ||refree.getP2Health() <0)
                {
                    // this line doesn't work
                    break;
                }
                
                //END SCRREN PART PART ENDS
                // ADD CONDTION IF END SCREEN PART IF TRUE THEN WHAT TO DO
            }
            end_sound.play(); 


        }

    if(state_of_main_menu == 3)
        break;// this is condition when EXIT is pressed in main menu
    }while(Initial::showExitPage() == 1);
    return 0;
}