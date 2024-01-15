#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

using namespace std;
using namespace sf;


#define Max_opcje 4

class Opcje
{
public:
	Opcje(float width, float height);
	bool open = true;

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

};