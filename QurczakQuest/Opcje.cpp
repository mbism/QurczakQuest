#include "Opcje.h"

#include "Opcje.h"


Opcje::Opcje(float width, float height)
{
	if (!font2.loadFromFile("font2.ttf"))
	{
		cout << "No font..";
	}

	if (!font.loadFromFile("font.ttf"))
	{
		cout << "No font..";
	}



	//Tytulik



	text1.setFont(font);
	text1.setString("Qurczak");
	text1.setCharacterSize(150);
	text1.setFillColor(Color(204, 0, 0));
	text1.setPosition(150, 10);



	text2.setFont(font);
	text2.setString("Quest");
	text2.setCharacterSize(150);
	text2.setFillColor(Color(204, 0, 0));
	text2.setPosition(250, 130);


	//PLAY
	opcje[0].setFont(font2);
	opcje[0].setFillColor(Color(0, 0, 0));
	opcje[0].setString("OPCJE");
	opcje[0].setCharacterSize(60);
	opcje[0].setPosition(400, 420);

	//OPTIONS

	opcje[1].setFont(font2);
	opcje[1].setFillColor(Color(0, 0, 0));
	opcje[1].setString("opcje");
	opcje[1].setCharacterSize(60);
	opcje[1].setPosition(340, 510);

	//EXIT

	opcje[2].setFont(font2);
	opcje[2].setFillColor(Color(0, 0, 0));
	opcje[2].setString("www");
	opcje[2].setCharacterSize(60);
	opcje[2].setPosition(410, 600);

	OpcjeSelected = -1;

}
Opcje::~Opcje()
{

}

void Opcje::draw(RenderWindow& window)
{
	while (window.isOpen()) {
		Event event;
		while (window.pollEvent(event)) {
			if (event.type == Event::Closed)
			{
				window.close();
			}
			if (event.type == Event::KeyPressed) if (event.key.code == Keyboard::Escape) window.close();
			if (event.type == Event::KeyReleased)
			{
				if (event.key.code == Keyboard::Up)
				{
					MoveUp();
					break;
				}
				if (event.key.code == Keyboard::Down)
				{
					MoveDown();
					break;
				}
			}
			if (Keyboard::isKeyPressed(Keyboard::Enter))
			{
				//window.close();
				
				if (OpcjeSelected == 0) {
					open = false;
					break;
				}
				else if (OpcjeSelected == 1) {
					//opcje
					break;
				}
				else if (OpcjeSelected == 2) {
					window.close();
				}
			}
			if (event.type == Keyboard::Escape) window.close();
		}

		if (open) {
			window.clear(Color(255, 255, 204));
			for (int i = 0; i < Max_opcje; i++)
			{
				window.draw(opcje[i]);
			}
			window.draw(text1);
			window.draw(text2);
			window.display();
		}
		else {
			break;
		}
	}
}


void Opcje::MoveUp()
{

	if (OpcjeSelected - 1 >= 0)
	{
		opcje[OpcjeSelected].setFillColor(Color::Black);

		OpcjeSelected--;
		if (OpcjeSelected == -1)
		{
			OpcjeSelected = 2;
		}
		opcje[OpcjeSelected].setFillColor(Color(204, 0, 0));
	}
}

void Opcje::MoveDown()
{
	if (OpcjeSelected + 1 < Max_opcje)
	{
		opcje[OpcjeSelected].setFillColor(Color::Black);
		OpcjeSelected++;
		if (OpcjeSelected == Max_opcje)
		{
			OpcjeSelected = 0;
		}
		opcje[OpcjeSelected].setFillColor(Color(204, 0, 0));
	}
}
