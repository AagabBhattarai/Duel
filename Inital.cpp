
#include "Initial.h"

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
					//RenderWindow Play(VideoMode(1366, 704), "game_name");
					RenderWindow OPTIONS(VideoMode(1366, 704), "OPTIONS");
					RenderWindow ABOUT(VideoMode(1366, 704), "ABOUT");

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

}
