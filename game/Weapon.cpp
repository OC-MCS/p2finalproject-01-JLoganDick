#include "Weapon.h"

Weapon::Weapon(Texture& weaponTexture) {
	weapon.setTexture(weaponTexture);
}

void Weapon::setWeaponPosition(Vector2f here) {
	weapon.setPosition(here);
}

void Weapon::draw(RenderWindow& win) {
	win.draw(weapon);
}

void Weapon::move(float i, float j) {
	weapon.move(i,j);
}

Vector2f Weapon::getPosition() {
	return weapon.getPosition();
}

FloatRect Weapon::getGlobalBounds() {
	return weapon.getGlobalBounds();
}

void Weapon::setPosition(float x, float y) {
	weapon.setPosition(x, y);
}







Missile::Missile(Texture& missileTexture) : Weapon(missileTexture)
{

}


void Missile::shootWeapon(bool& isMissileInFlight, Sprite ship, Event event) {
	if (event.type == Event::KeyPressed)
	{
		if (event.key.code == Keyboard::Space && !isMissileInFlight)
		{
			isMissileInFlight = true;
			Vector2f pos = ship.getPosition();
			setWeaponPosition(pos);
			// handle space bar
		}

	}
}



void Bomb::shootWeapon() {


}