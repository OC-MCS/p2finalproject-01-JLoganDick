#include "bombSet.h"

BombSet::BombSet() {

}

void BombSet::createBomb(Vector2f enemyPos) {

	Bomb bomb(bombTexture, enemyPos);
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
	for (iter = bombs.begin(); iter != bombs.end() && !hit;) {											// runs through the linked list of bombs

		if ((iter)->getSprite().getGlobalBounds().intersects(ship.getSprite().getGlobalBounds())) {		// cheks for intersection of bomb with ship
			hit = true;
			menu.loseLife();																			// Decremints lives by 1
		}
		if (!hit) {
			iter++;																						// moves to next bomb if bomb didnt hit ship
		}
	}
	return hit;
}

void BombSet::clear() {
	bombs.clear();
}