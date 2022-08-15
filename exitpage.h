#pragma once

#pragma once
#include<SFML/Graphics.hpp>
#include<iostream>
using namespace std;
using namespace sf;

//#define Max_main_menu 2
class exitpage
{
public:
	exitpage(float width, float height);

	void draw(RenderWindow& window);
	void MoveUp();
	void MoveDown();

	int MainMenuPressed()
	{
		return MainMenuSelected;
	}
	~exitpage();

private:
	int MainMenuSelected;
	Font font;
	Text mainMenu[2];

};

