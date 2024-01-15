#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

using namespace std;
using namespace sf;


#define Max_menu 4

class Menu
{
public:
	Menu(float width, float height);
	bool open = true;

	void draw(RenderWindow& window);
	void MoveUp();
	void MoveDown();

	int MenuPressed()
	{
		return MainMenuSelected;
	}
	~Menu();

private:
	int MainMenuSelected;
	Font font;
	Font font2;
	Text mainMenu[Max_menu];
	Text text1;
	Text text2;
	int windowHeight = 1920;
	int windowWidth = 1080;

};



