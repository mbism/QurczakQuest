#include <SFML/Graphics.hpp>
#include <iostream>
#include "WrogLas.h"

using namespace std;
using namespace sf;

class WrogLas {
private:

	Texture tekstura;
	string sciezkaTekstury = "images/wiewiora.png"; //na razie wiewi�rka ale zmieni� na lisa
	int podloga = 550 - 40;
	int y = podloga;
	int x = 1080;

public:

	Sprite sprite;

	void rysuj() {
		if (!tekstura.loadFromFile(sciezkaTekstury))
		{
			cout << "Nie za�adowano tekstury lesnego przeciwnika - wiewiorki" << endl;
		}
		else {
			sprite.setTexture(tekstura);

			int XIndex = 0;
			int YIndex = 0;

			sprite.setTextureRect(IntRect(XIndex * 52, YIndex * 52, 52, 52));
			sprite.scale(Vector2f(2, 2));

			sprite.setPosition(Vector2f(1100, 545));
		}
	}
};