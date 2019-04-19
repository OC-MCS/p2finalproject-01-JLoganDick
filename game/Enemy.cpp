#include "Enemy.h"

Enemy::Enemy(Texture& enemyTexture, float x, float y, int level) {
	if (level == 1) {
		if (!enemyTexture.loadFromFile("enemy.png")) {
			cout << "Unable to load enemy texture!" << endl;
			exit(EXIT_FAILURE);
		}
	}
	else {
		if (!enemyTexture.loadFromFile("enemy2.png")) {
			cout << "Unable to load enemy texture!" << endl;
			exit(EXIT_FAILURE);
		}
	}

	enemy.setTexture(enemyTexture);
	float enemyX = x;
	float enemyY = y;
	enemy.setPosition(enemyX, enemyY);
}

void Enemy::moveEnemy() {
	const float DISTANCE = 0.1f;
	enemy.move(0, DISTANCE);
}

void Enemy::setPosition(float x, float y) {
	enemy.setPosition(x, y);
}

Vector2f Enemy::getPostion() {
	return enemy.getPosition();
}

void Enemy::draw(RenderWindow& window) {
	window.draw(enemy);
}

FloatRect Enemy::getGlobalBounds() {
	return enemy.getGlobalBounds();
}

Sprite Enemy::getEnemy() {
	return enemy;
}