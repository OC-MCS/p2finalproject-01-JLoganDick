#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
using namespace std;
using namespace sf;

class Weapon
{
private:
	Sprite weapon;

public:
	Weapon(Texture& weaponTexture);
	void setWeaponPosition(Vector2f here);
	virtual void shootWeapon() {};
	void draw(RenderWindow& win);
	void move(float i, float j);
	Vector2f getPosition();
	FloatRect getGlobalBounds();
	void setPosition(float x, float y);
};


class Missile: public Weapon
{
private:

public:
	Missile(Texture& missileTexture);
	void shootWeapon(bool& isMissileInFlight, Sprite ship, Event event);
};


class Bomb : public Weapon
{
private:


public:
	void shootWeapon();


};
