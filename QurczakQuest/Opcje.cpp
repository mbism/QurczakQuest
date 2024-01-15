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
	 
	//KOLKA

	kolo1.setRadius(30);
	kolo1.setFillColor(Color::Green);
	kolo1.setPosition(678, 878);

	kolo2.setRadius(30);
	kolo2.setFillColor(Color::Green);
	kolo2.setPosition(1190, 878);

	//Tytulik



text1.setFont(font);
text1.setString("Qurczak");
text1.setCharacterSize(230);
text1.setFillColor(Color(204, 0, 0));
text1.setPosition(500, 30);



text2.setFont(font);
text2.setString("Quest");
text2.setCharacterSize(230);
text2.setFillColor(Color(204, 0, 0));
text2.setPosition(600, 230);



//VOLUME
opcje[0].setFont(font2);
opcje[0].setFillColor(Color(0, 0, 0));
opcje[0].setString("VOLUME");
opcje[0].setCharacterSize(80);
opcje[0].setPosition(800, 600);

//STRZALAKI

opcje[1].setFont(font2);
opcje[1].setFillColor(Color(0, 0, 0));
opcje[1].setString("<- ^ ->");
opcje[1].setCharacterSize(80);
opcje[1].setPosition(1250, 850);

//WSAD

opcje[2].setFont(font2);
opcje[2].setFillColor(Color(0, 0, 0));
opcje[2].setString("wsad");
opcje[2].setCharacterSize(80);
opcje[2].setPosition(450, 850);

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
			if (wsad == true) { window.draw(kolo1); }
			if (wsad == false) { window.draw(kolo2); }

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
