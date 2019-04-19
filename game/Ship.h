#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include "Weapon.h"
using namespace std;
using namespace sf;

class Ship {
private:
	Sprite ship;
public:
	Ship(RenderWindow& win, Texture& shipTexture);
	void moveShip();
	void draw(RenderWindow& win);
	Sprite getShip();
	Vector2f getPosition();
	Sprite getSprite();
};
