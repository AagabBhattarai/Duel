
//#include "MainMenu.h"
#include "exitpage.h"

exitpage::exitpage(float width, float height)
{
	if (!font.loadFromFile("font.otf"))
	{
		cout << "NO FONT IS HERE";
	}
	/*
	//Play
	mainMenu[0].setFont(font);
	mainMenu[0].setFillColor(Color::White);
	mainMenu[0].setString("Play");
	mainMenu[0].setCharacterSize(70);
	mainMenu[0].setPosition(400, 200);
	//options
	mainMenu[1].setFont(font);
	mainMenu[1].setFillColor(Color::White);
	mainMenu[1].setString("Options");
	mainMenu[1].setCharacterSize(70);
	mainMenu[1].setPosition(400, 300);
	//about
	mainMenu[2].setFont(font);
	mainMenu[2].setFillColor(Color::White);
	mainMenu[2].setString("About");
	mainMenu[2].setCharacterSize(70);
	mainMenu[2].setPosition(400, 400);
	//exit
	mainMenu[3].setFont(font);
	mainMenu[3].setFillColor(Color::White);
	mainMenu[3].setString("Exit");
	mainMenu[3].setCharacterSize(70);
	mainMenu[3].setPosition(400, 500);
	*/
	//return to main menu
	mainMenu[0].setFont(font);
	mainMenu[0].setFillColor(Color::White);
	mainMenu[0].setString("RETURN TO MAIN MENU");
	mainMenu[0].setCharacterSize(70);
	mainMenu[0].setPosition(400, 200);
	MainMenuSelected = 0;
	//exit
	mainMenu[1].setFont(font);
	mainMenu[1].setFillColor(Color::White);
	mainMenu[1].setString("Exit");
	mainMenu[1].setCharacterSize(70);
	mainMenu[1].setPosition(400, 500);
}

exitpage::~exitpage()
{
	//destructor
}

//draw Mainmenu
void exitpage::draw(RenderWindow& window)
{
	for (int i = 0; i < 2; ++i)
	{
		window.draw(mainMenu[i]);
	}
}

//MoveUp
void exitpage::MoveUp()
{
	if (MainMenuSelected - 1 >= 0)
	{
		mainMenu[MainMenuSelected].setFillColor(Color::White);

		MainMenuSelected--;
		if (MainMenuSelected == -1) {
			MainMenuSelected = 2;
		}
		mainMenu[MainMenuSelected].setFillColor(Color::Blue);
	}
}

//Move Down
void exitpage::MoveDown()
{
	if (MainMenuSelected + 1 <= 2)
	{
		mainMenu[MainMenuSelected].setFillColor(Color::White);

		MainMenuSelected++;
		if (MainMenuSelected == 2) {
			MainMenuSelected = 0;
		}
		mainMenu[MainMenuSelected].setFillColor(Color::Blue);

	}
}

