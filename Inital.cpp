
#include "Initial.h"
#include "exitpage.h"

using namespace sf;

int Initial::showMainMenu()//main page
{
	//make a main window
	RenderWindow MENU(VideoMode(1366, 704), "Duel", Style::Default);
	MainMenu mainMenu(MENU.getSize().x, MENU.getSize().y);

	//set background

	RectangleShape background;
	background.setSize(Vector2f(1366, 704));
	Texture Maintexture;
	Maintexture.loadFromFile("background_for_mainmenu.png");
	background.setTexture(&Maintexture);

	//photo to the game

	while (MENU.isOpen())
	{
		Event event;
		while (MENU.pollEvent(event))
		{
			if (event.type == Event::Closed)
			{
				MENU.close();
			}
			if (event.type == Event::KeyReleased)
			{
				if (event.key.code == Keyboard::Up)
				{
					mainMenu.MoveUp();
					break;
				}
				if (event.key.code == Keyboard::Down)
				{
					mainMenu.MoveDown();
					break;
				}
				if (event.key.code == Keyboard::Return)
				{
					RenderWindow OPTIONS(VideoMode(1366, 704), "OPTIONS");
					RenderWindow ABOUT(VideoMode(1366, 704), "HISTORY");



					sf::Font font;
					if (!font.loadFromFile("font.otf"))
					{
						std::cout << "Calibri ttf";
						return -1;
					}
					sf::Text total_match;
					total_match.setFont(font);
					total_match.setFillColor(sf::Color::White);
					total_match.setCharacterSize(70);
					// total_match.setOrigin(total_match.getCharacterSize()/2, total_match.getCharacterSize()/2);
					total_match.setPosition(0,0);


					sf::Text ken_match;
					ken_match.setFont(font);
					ken_match.setFillColor(sf::Color::White);
					ken_match.setCharacterSize(70);
					// ken_match.setOrigin(ken_match.getCharacterSize()/2, to_match.getCharacterSize()/2);
					ken_match.setPosition(0,200);

					sf::Text ryu_match;
					ryu_match.setFont(font);
					ryu_match.setFillColor(sf::Color::White);
					ryu_match.setCharacterSize(70);
					// ryu_match.setOrigin(ken_match.getCharacterSize()/2, total_match.getCharacterSize()/2);
					ryu_match.setPosition(0,400);


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
					gridsprite.setPosition(ABOUT.getSize().x / 2, ABOUT.getSize().y / 2);


					int total_matches{};
					int ken_wins{};
					int ryu_wins{};
					fstream match_record_read("match_history.dat", std::ios::in | std::ios::binary);
					if(!match_record_read)
					{
						std::cout<<"error accessing record file";
					}

					if(match_record_read)
					{
						match_record_read.read(reinterpret_cast<char*>(&total_matches),sizeof(total_matches));
						match_record_read.read(reinterpret_cast<char*>(&ken_wins),sizeof(ken_wins));
						match_record_read.read(reinterpret_cast<char*>(&ryu_wins),sizeof(ryu_wins));
					}

					std::string str = std::to_string(total_matches);
    				total_match.setString("Total Matches Played:"+ str);

					std::string str1 = std::to_string(ken_wins);
    				ken_match.setString("KEN'S WINS:"+ str1);

					std::string str2 = std::to_string(ryu_wins);
    				ryu_match.setString("RYU'S WINS:"+ str2);

					int x = mainMenu.MainMenuPressed();
					if (x == 0)
					{
						return 1;
						
					}
					if (x == 1)
					{
						while (OPTIONS.isOpen())
						{
							Event aevent;
							while (OPTIONS.pollEvent(aevent))
							{
								if (aevent.type == Event::Closed)
								{
									OPTIONS.close();
								}
								if (aevent.type == Event::KeyPressed)
								{
									if (aevent.key.code == Keyboard::Escape)
									{
										OPTIONS.close();
									}
								}
							}
							//Play.close();
							OPTIONS.clear();
							ABOUT.close();

							OPTIONS.display();
						}
					}
					if (x == 2)
					{
						while (ABOUT.isOpen())
						{
							Event aevent;
							while (ABOUT.pollEvent(aevent))
							{
								if (aevent.type == Event::Closed)
								{
									ABOUT.close();
								}
								if (aevent.type == Event::KeyPressed)
								{
									if (aevent.key.code == Keyboard::Escape)
									{
										ABOUT.close();
									}
								}
							}
						//	Play.close();
							OPTIONS.clear();
							ABOUT.clear();
							ABOUT.draw(gridsprite);
							ABOUT.draw(total_match);
							ABOUT.draw(ken_match);
							ABOUT.draw(ryu_match);

							ABOUT.display();
						}
					}
					if (x == 3)
						MENU.close();
					break;
				}

			}
		}
		MENU.clear();
		MENU.draw(background);
		mainMenu.draw(MENU);
		MENU.display();
	}
	return 3;
}

int Initial::showExitPage()
{
	//make a exit window
	RenderWindow EXIT(VideoMode(1366, 704), "Duel", Style::Default);
	exitpage exitpage(EXIT.getSize().x, EXIT.getSize().y);

	//set background

	RectangleShape background;
	background.setSize(Vector2f(1366, 704));
	Texture Maintexture;
	Maintexture.loadFromFile("grid.jpg");
	background.setTexture(&Maintexture);

	//photo to the game

	while (EXIT.isOpen())
	{
		Event event;
		while (EXIT.pollEvent(event))
		{
			if (event.type == Event::Closed)
			{
				EXIT.close();
			}
			if (event.type == Event::KeyReleased)
			{
				if (event.key.code == Keyboard::Up)
				{
					exitpage.MoveUp();
					break;
				}
				if (event.key.code == Keyboard::Down)
				{
					exitpage.MoveDown();
					break;
				}
				if (event.key.code == Keyboard::Return)
				{

					int x = exitpage.MainMenuPressed();
					if (x == 0)
					{
						return 1;
					}
					/*
					if (x == 1)
					{
						while (OPTIONS.isOpen())
						{
							Event aevent;
							while (OPTIONS.pollEvent(aevent))
							{
								if (aevent.type == Event::Closed)
								{
									OPTIONS.close();
								}
								if (aevent.type == Event::KeyPressed)
								{
									if (aevent.key.code == Keyboard::Escape)
									{
										OPTIONS.close();
									}
								}
							}
							//Play.close();
							OPTIONS.clear();
							ABOUT.close();

							OPTIONS.display();
						}
					}
					if (x == 2)
					{
						while (ABOUT.isOpen())
						{
							Event aevent;
							while (ABOUT.pollEvent(aevent))
							{
								if (aevent.type == Event::Closed)
								{
									ABOUT.close();
								}
								if (aevent.type == Event::KeyPressed)
								{
									if (aevent.key.code == Keyboard::Escape)
									{
										ABOUT.close();
									}
								}
							}
							//	Play.close();
							OPTIONS.clear();
							ABOUT.clear();

							ABOUT.display();
						}
					}
					*/
					if (x == 1)
						EXIT.close();
					break;
				}

			}
		}
		EXIT.clear();
		EXIT.draw(background);
		exitpage.draw(EXIT);
		EXIT.display();
	}
	return 5; //random
}