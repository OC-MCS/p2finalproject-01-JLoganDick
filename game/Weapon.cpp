#include "Weapon.h"

Weapon::Weapon(Texture& weaponTexture, Vector2f shipPos) {
	weapon.setTexture(weaponTexture);
	weapon.setPosition(shipPos);
}

void Weapon::setWeaponPosition(Vector2f here) {
	weapon.setPosition(here);
}

void Weapon::draw(RenderWindow& win) {
	win.draw(weapon);
}

void Weapon::move(float x, float y) {
	weapon.move(x,y);
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

Sprite Weapon::getSprite() {
	return weapon;
}

Missile::Missile(Texture& missileTexture, Vector2f pos) : Weapon(missileTexture, pos){
	if (!missileTexture.loadFromFile("missile.png")) {
		cout << "Unable to load enemy texture!" << endl;
		exit(EXIT_FAILURE);
	}

}


Bomb::Bomb(Texture& bombTexture, Vector2f enemyPos) : Weapon(bombTexture, enemyPos) {
	if (!bombTexture.loadFromFile("bomb.png")) {
		cout << "Unable to load enemy texture!" << endl;
		exit(EXIT_FAILURE);
	}
}
