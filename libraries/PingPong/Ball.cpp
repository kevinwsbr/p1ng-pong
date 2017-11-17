#include "Arduino.h"
#include "Ball.h"

Ball::Ball(int x, int y, int headingX, int headingY)
{
	_x = x;
	_y = y;
	_headingX = headingX;
	_headingY = headingY;
}

int Ball::getX()
{
	return _x;
}

int Ball::getY()
{
	return _y;
}

void Ball::setX(int x)
{
	_x = x;
}

void Ball::setY(int y)
{
	_y = y;
}

void Ball::decrementX()
{
	_x--;
}

void Ball::decrementY()
{
	_y--;
}

void Ball::incrementX()
{
	_x++;
}

void Ball::incrementY()
{
	_y++;
}

int Ball::getHeadingX()
{
	return _headingX;
}

int Ball::getHeadingY()
{
	return _headingY;
}

void Ball::setHeadingX(int headingX)
{
	_headingX = headingX;
}

void Ball::setHeadingY(int headingY)
{
	_headingY = headingY;
}

void Ball::invertHeadingX()
{
	tone(8,392,50);
	_headingX *= -1;
}

void Ball::invertHeadingY()
{
	tone(8,392,50);
	_headingY *= -1;
}