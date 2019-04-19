#pragma once
#include "Weapon.h"

class Enemy
{
private:
	Sprite enemy;
	Texture Bomb;

public:
	Enemy(Texture& enemyTexture, float x, float y, int level);
	void moveEnemy();
	void setPosition(float x, float y);
	void draw(RenderWindow& window);
	FloatRect getGlobalBounds();
	Sprite getEnemy();
	Vector2f getPostion();
};