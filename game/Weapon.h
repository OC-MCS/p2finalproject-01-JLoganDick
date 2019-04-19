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
	Weapon(Texture& weaponTexture, Vector2f shipPos);
	void setWeaponPosition(Vector2f here);
	void draw(RenderWindow& win);
	void move(float x, float y);
	Vector2f getPosition();
	FloatRect getGlobalBounds();
	void setPosition(float x, float y);
	Sprite getSprite();
};


class Missile: public Weapon
{
private:

public:
	Missile(Texture& missileTexture, Vector2f pos);
};


class Bomb : public Weapon
{
private:


public:
	Bomb(Texture& bombTexture, Vector2f enemyPos);
	int begin();
};
