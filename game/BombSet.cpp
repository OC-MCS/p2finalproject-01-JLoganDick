#include "bombSet.h"

BombSet::BombSet() {

}

void BombSet::createBomb(Vector2f ailenPos) {

	Bomb bomb(bombTexture, ailenPos);
	bombs.push_back(bomb);

}

void BombSet::move(float x, float y) {
	list<Bomb>::iterator iter;
	for (iter = bombs.begin(); iter != bombs.end(); iter++)
	{
		iter->move(x, y);
	}
}

void BombSet::draw(RenderWindow& win) {
	list<Bomb>::iterator iter;
	for (iter = bombs.begin(); iter != bombs.end(); iter++)
	{
		iter->draw(win);
	}
}

void BombSet::outOfBounds() {
	list<Bomb>::iterator iter;
	for (iter = bombs.begin(); iter != bombs.end();)
	{
		bool out = false;
		Vector2f vec = iter->getPosition();
		if (vec.y > 600) {
			out = true;
			iter = bombs.erase(iter);
		}
		if (!out) {
			iter++;
		}
	}
}

void BombSet::randBomb(EnemySet &es, int &timer) {
	if (timer % 30 == 0) {
		srand(time(0));
		int num = rand() % es.getSize();
		Sprite temp = es.getSprite(num);
		Vector2f bombLoc = temp.getPosition();
		createBomb(bombLoc);
		timer = 0;
	}
	timer++;
}

bool BombSet::hit(Ship &ship, userMenu &menu) {
	int index;
	list<Bomb>::iterator iter;
	bool hit = false;
	for (iter = bombs.begin(); iter != bombs.end() && !hit;) {
		hit = false;

		if ((iter)->getSprite().getGlobalBounds().intersects(ship.getSprite().getGlobalBounds())) {
			iter = bombs.erase(iter);
			hit = true;
			menu.loseLife();
		}
		if (!hit) {
			iter++;
		}
	}
	return hit;
}