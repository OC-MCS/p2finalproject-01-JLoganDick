#include "Ship.h"
#include "Weapon.h"
#include <list>

Ship::Ship(RenderWindow& win, Texture& shipTexture) {
	
	ship.setTexture(shipTexture);

	float shipX = win.getSize().x / 2.0f;
	float shipY = win.getSize().y / 1.2f;
	ship.setPosition(shipX, shipY);
}

void Ship::draw(RenderWindow& win) {
	win.draw(ship);
}

Sprite Ship::getShip() {
	return ship;
}

void Ship::moveShip() {

	const float DISTANCE = 5.0;

	if (Keyboard::isKeyPressed(Keyboard::Left) && ship.getPosition().x > 0)
	{
		// left arrow is pressed: move our ship left 5 pixels
		// 2nd parm is y direction. We don't want to move up/down, so it's zero.
		ship.move(-DISTANCE, 0);
	}
	else if (Keyboard::isKeyPressed(Keyboard::Right) && ship.getPosition().x < 780)
	{
		// right arrow is pressed: move our ship right 5 pixels
		ship.move(DISTANCE, 0);
	}

}

Vector2f Ship::getPosition() {
	return ship.getPosition();
}

Sprite Ship::getSprite() {
	return ship;
}
