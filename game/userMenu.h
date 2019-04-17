#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
using namespace std;
using namespace sf;

class userMenu {
private:
	int level;
	RectangleShape button;
	int lives;
	int kills;
public:
	userMenu(int windowX, int windowY);
	RectangleShape getButton();
	bool handelMouseUp(Vector2f mousePos);
	void draw(RenderWindow& win);

};
