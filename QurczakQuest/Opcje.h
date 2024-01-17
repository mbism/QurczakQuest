#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "Menu.h"


using namespace std;
using namespace sf;


#define Max_opcje 4

class Opcje
{
public:
	Opcje(float width, float height);
	bool open = true;
	bool wsad = true;

	void draw(RenderWindow& window);
	void MoveUp();
	void MoveDown();

	int OpcjePressed()
	{
		return OpcjeSelected;
	}
	~Opcje();

private:
	int OpcjeSelected;
	Font font;
	Font font2;
	Text opcje[Max_opcje];
	Text text1;
	Text text2;
	CircleShape kolo1;
	CircleShape kolo2;

};