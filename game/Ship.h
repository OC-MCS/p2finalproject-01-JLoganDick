#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
using namespace std;
using namespace sf;

class Ship {
private:
	Sprite ship;
	// is hit?
	int lives;
public:
	Ship(RenderWindow& win, Texture& shipTexture);
	void moveShip();
	void draw(RenderWindow& win);
	Sprite getShip();
	Vector2f getPosition();
};
