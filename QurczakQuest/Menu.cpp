#include "Menu.h"
#include "Opcje.h"


Menu::Menu(float width, float height)
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
text1.setCharacterSize(230);
text1.setFillColor(Color(204, 0, 0));
text1.setPosition(500, 30);



text2.setFont(font);
text2.setString("Quest");
text2.setCharacterSize(230);
text2.setFillColor(Color(204, 0, 0));
text2.setPosition(600, 230);


//PLAY
mainMenu[0].setFont(font2);
mainMenu[0].setFillColor(Color(0, 0, 0));
mainMenu[0].setString("PLAY");
mainMenu[0].setCharacterSize(80);
mainMenu[0].setPosition(880, 600);

//OPTIONS

mainMenu[1].setFont(font2);
mainMenu[1].setFillColor(Color(0, 0, 0));
mainMenu[1].setString("OPTIONS");
mainMenu[1].setCharacterSize(80);
mainMenu[1].setPosition(810, 750);

//EXIT

mainMenu[2].setFont(font2);
mainMenu[2].setFillColor(Color(0, 0, 0));
mainMenu[2].setString("EXIT");
mainMenu[2].setCharacterSize(80);
mainMenu[2].setPosition(880, 900);

	MainMenuSelected = -1;

}
Menu::~Menu()
{

}

void Menu::draw(RenderWindow& window)
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

				if (MainMenuSelected == 0) {
					open = false;
					break;
				}
				else if (MainMenuSelected == 1) {
					Opcje opcje = Opcje(windowWidth, windowHeight);
					while (opcje.open) {
						opcje.draw(window);
						wsad = opcje.wsad;
					}
					cout << open << endl;
				}
				else {
					window.close();
				}
			}
			if (event.type == Keyboard::Escape) window.close();
		}

		if (open) {
			cout << "aaaa" << endl;
			window.clear(Color(255, 255, 204));
			for (int i = 0; i < Max_menu; i++)
			{
				window.draw(mainMenu[i]);
			}
			window.draw(text1);
			window.draw(text2);
			window.display();
		}
		else break;
	}
}


void Menu::MoveUp()
{

	if (MainMenuSelected - 1 >= 0)
	{
		mainMenu[MainMenuSelected].setFillColor(Color::Black);

		MainMenuSelected--;
		if (MainMenuSelected == -1)
		{
			MainMenuSelected = 2;
		}
		mainMenu[MainMenuSelected].setFillColor(Color(204, 0, 0));
	}
}

void Menu::MoveDown()
{
	if (MainMenuSelected + 1 < Max_menu)
	{
		mainMenu[MainMenuSelected].setFillColor(Color::Black);
MainMenuSelected++;
		if (MainMenuSelected == Max_menu)
		{
			MainMenuSelected = 0;
		}
		mainMenu[MainMenuSelected].setFillColor(Color(204, 0, 0));
	}
}
