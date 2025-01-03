#include "Human.h"
Human::Human(int x, int y)
{
	this->x = x;
	this->y = y;
	dead = false;
}
int Human::getX()
{
	return x;
}
int Human::getY()
{
	return y;
}
void Human::up()
{
	if (checkFrame(x - 6, y))
		x -= 6;
}
void Human::down()
{
	if (checkFrame(x + 6, y))
		x += 6;
}
void Human::left()
{
	if (checkFrame(x, y - 1))
		--y;
}
void Human::right()
{
	if (checkFrame(x, y + 1))
		++y;
}
bool Human::checkFrame(int a, int b)
{
	return ((0 <= a && a < 42) && (25 <= b && b < 135));
}
bool Human::atFinish()
{
	return (x == 0);
}
bool Human::collide(Obstacle* ve)
{
	int tempX = ve->getMX();
	int tempY = ve->getMY();

	int sizeO = (ve->texture[0]).length();
	int sizeH = 3;

	if (x == tempX && !((y + sizeH <= tempY) || (tempY + sizeO <= y)))
	{
		dead = true;
		return true;
	}
	else
		return false;
}

bool Human::isDead()
{
	return dead;
}