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
#include "Power.h"
#include <fstream>



int main(int argc, char** argv)
{   
    int state_of_main_menu{};
    do
    {    
        state_of_main_menu = Initial::showMainMenu();
        if ( state_of_main_menu == 1)
        {
        
            sf::RenderWindow window(sf::VideoMode(1366, 704), "Duel");
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

            //POWER 
            sf::Texture power;
            if(!power.loadFromFile("powerup.png"))
            {
                std::cout<<"Error for spark image";
                return -1;
            }
            spark.setRepeated(true);
            Power powerup(&power);

            //Fighter 
            sf::Texture tplayer1;  
            if (!tplayer1.loadFromFile("ryu.png"))
            {
                std::cout << "error for texture load player";
                return -2;
            }
            tplayer1.setRepeated(true);

            Player player1(&tplayer1, sf::Vector2u(16, 10), 150.0f, true, &spark); //player1 vanne object create garyom.


            sf::Texture tplayer2;
            if (!tplayer2.loadFromFile("kens.png"))
            {
                std::cout << "error for texture load player";
                return -2;
            }
            tplayer2.setRepeated(true);

            Player player2(&tplayer2, sf::Vector2u(16, 10), 150.0f, false, &spark);

            float deltaTime = 0.f; //this is the difference in time to switch between frames
            sf::Clock clock;
            sf::Clock clockForRoundTime;


            //For Font
            sf::Font font;
            if (!font.loadFromFile("font.otf"))
            {
                std::cout << "Calibri ttf";
                return -1;
            }
            sf::Text end_text;
            end_text.setFont(font);
	        end_text.setFillColor(sf::Color(255,129,0));
	        end_text.setCharacterSize(70);
            // end_text.setOrigin(end_text.getCharacterSize()/2, end_text.getCharacterSize()/2);
	        end_text.setPosition(wsize.x/2-20, wsize.y/2-20);
        

            //SOUND - SOUND
            sf::Music music;
            if(!music.openFromFile("music.wav"));
            {
                std::cout<<"background_music.wav opening";
                // return -2;s// program should terminate but terminates even though open for file is successful
            }
            music.setVolume(10.0f);
            music.setLoop(true);
            music.play();


            sf::SoundBuffer fire_soundBuffer;
            if(!fire_soundBuffer.loadFromFile("fire.wav"))
            {
                std::cout << "air audio file problem";
                return -2;
            }
            sf::Sound power_sound;
            power_sound.setBuffer(fire_soundBuffer);


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

            sf::SoundBuffer grunt_soundBuffer;
            if(!grunt_soundBuffer.loadFromFile("grunt.wav"))
            {
                std::cout << "grunt audio file problem";
                return -2;
            }
            sf::Sound grunt_sound;
            grunt_sound.setBuffer(grunt_soundBuffer);


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
                std::cout << "End.ogg audio file problem";
                return -2;
            }
            sf::Sound end_sound;
            end_sound.setBuffer(end_soundBuffer);


            sf::SoundBuffer win_soundBuffer;
            if(!win_soundBuffer.loadFromFile("Win.wav"))
            {
                std::cout << "win.wav audio file problem";
                return -2;
            }
            sf::Sound win_sound;
            win_sound.setBuffer(win_soundBuffer);
            // win_sound.setPlayingOffset(sf::seconds(3.f));
        


            Timer timer90sec(font, clockForRoundTime.getElapsedTime().asSeconds());
            window.setKeyRepeatEnabled(false);


            //For Refree;

            Refree refree(500.0f, 500.0f);

            //these following variables are for spark animaton
            float totaltime{};
            int spark_count_p1{0};
            int spark_count_p2{0};
            sf::Vector2f p2_position;
            float total_power_time{};
            int power_count{0};
            float end_counter{0};
            bool match_over = false;

            fstream match_record_read("match_history.dat", std::ios::in | std::ios::binary);
            if(!match_record_read)
            {
                std::cout<<"error accessing record file";
            }
            int total_matches{};
            int ken_wins{};
            int ryu_wins{};
            bool ken_won = false;
            bool ryu_won = false;

            if(match_record_read)
            {
                match_record_read.read(reinterpret_cast<char*>(&total_matches),sizeof(total_matches));
                match_record_read.read(reinterpret_cast<char*>(&ken_wins),sizeof(ken_wins));
                match_record_read.read(reinterpret_cast<char*>(&ryu_wins),sizeof(ryu_wins));
            }
            
            //game loop starts now
            total_matches++;
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

                if(!match_over)
                {
                    player1.Update(deltaTime, wsize, true, Collision::checkCollision(player1.playerPosition_x(), player2.playerPosition_x(), player1.playerPosition_y(), player2.playerPosition_y()));
                    player2.Update(deltaTime, wsize, false, Collision::checkCollision(player1.playerPosition_x(), player2.playerPosition_x(), player1.playerPosition_y(), player2.playerPosition_y()));
                }

                //this is for starting point of the power
                if(player2.player_state == POWER && player2.isTransitionPhase())
                {
                    p2_position.x = player2.playerPosition_x();
                    p2_position.y = player2.playerPosition_y()-20;
                    powerup.setPosition(p2_position, player2.isFacingRight());
                    power_sound.play();
                }
                //this is for the position update of power
                if(player2.player_state == POWER && player2.isImpactPhase() &&!(Collision::checkCollisionPower(player1.playerPosition_x(), p2_position.x, player1.playerPosition_y(), p2_position.y)))
                {   
                    if(player2.isFacingRight() == false)
                        p2_position.x -= 20;
                    else if (player2.isFacingRight()==true)
                        p2_position.x += 20;
                    powerup.setPosition(p2_position, player2.isFacingRight());
                }


                float p1_health = refree.getP1Health();
                float p2_health = refree.getP2Health();

                if  (Collision::checkCollision(player1.playerPosition_x(), player2.playerPosition_x(), player1.playerPosition_y(), player2.playerPosition_y())
                    && (player1.isTransitionPhase() || player2.isTransitionPhase())
                    ) 
                    
                {
                    refree.mediate(player1.player_state, player2.player_state, player1.isImpactPhase(), player2.isImpactPhase(), player1.isFacingRight(),!(player2.isFacingRight()), player1.isCombo());
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

                if(player1.isTransitionPhase() && (player1.player_state == PlayerState::PUNCH || player1.player_state == PlayerState::KICK))
                {
                    grunt_sound.play();
                }

                if(player2.isTransitionPhase() && (player2.player_state == PlayerState::PUNCH || player2.player_state == PlayerState::KICK || player2.player_state == PlayerState::POWER))
                {
                    grunt_sound.play();
                }
                //Following part is for super move check
                if(Collision::checkCollisionPower(player1.playerPosition_x(), p2_position.x, player1.playerPosition_y(), p2_position.y) && player2.isImpactPhase() )
                {
                    refree.setP1Health(2);
                    if(player1.player_state != JUMP && player1.isFacingRight())
                        player1.player_state = PlayerState::REACTION;
                }
                
                
                window.clear();
                window.draw(gridsprite);
                timer90sec.Draw(window);
                player1.Draw(window);
                player2.Draw(window);

                total_power_time += deltaTime;
                if(player2.player_state == POWER && player2.isImpactPhase())
                {
                    if(total_power_time >= 0.1)
                    {
                        power_count++;
                        powerup.Update(power_count);
                        total_power_time =0;
                    }
                    if(power_count > 4)
                    {  
                        power_count = 0;
                        p2_position.x = 0;
                        p2_position.y=0;
                    }
                    powerup.Draw(window);
                }


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


                if(clockForRoundTime.getElapsedTime().asSeconds()  < 2)
                {
                    end_sound.play();
                    // win_sound.play();
                    
                    end_text.setScale(2,2);
                    end_text.setPosition(wsize.x/2-220,wsize.y/2-200);
                    end_text.setString("FIGHT!!!");
                    window.draw(end_text);
                }
                
                if(refree.getP1Health() <0 || refree.getP2Health() <0 || clockForRoundTime.getElapsedTime().asSeconds() > 90) 
                {
                    // win_sound.play();
                    match_over = true;
                    end_counter += deltaTime;
                }
                
                if(end_counter <= 5.0f && match_over)
                {
                    win_sound.play();
                    if(refree.getP1Health() < 0 || refree.getP1Health() < refree.getP2Health())
                    {
                        ken_won = true;
                        end_text.setPosition(wsize.x/2-320, wsize.y/2-200);
                        end_text.setString("KEN WINS!!!");
                    }
                    else if(refree.getP2Health() < 0  || refree.getP2Health() < refree.getP1Health())
                    {
                        ryu_won = true;
                        end_text.setPosition(wsize.x/2-320, wsize.y/2-200);
                        end_text.setString("RYU WINS!!!");
                    }
                    window.draw(end_text);
                    
                }

                window.display();
                if(end_counter > 5)
                {
                    break;
                }
               
            }
            match_record_read.close();
            
            if(ken_won)
                ken_wins++;
            else if(ryu_won)
                ryu_wins++;
            fstream match_record_write("match_history.dat", std::ios::out | std::ios::binary);
            match_record_write.write(reinterpret_cast<char*>(&total_matches), sizeof(int));
            match_record_write.write(reinterpret_cast<char*>(&ken_wins), sizeof(int));
            match_record_write.write(reinterpret_cast<char*>(&ryu_wins), sizeof(int));
            match_record_write.close();

        }

    if(state_of_main_menu == 3)
        break;// this is condition when EXIT is pressed in main menu
    }while(Initial::showExitPage() == 1);
    return 0;
}