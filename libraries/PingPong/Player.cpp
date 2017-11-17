#include "Arduino.h"
#include "Player.h"

Player::Player(int score, int position)
{
	_score = score;
	_position = position;
}

int Player::getScore()
{
	return _score;
}

void Player::setScore(int score)
{
	_score = score;
}

void Player::incrementScore()
{
	_score++;
}

void Player::decrementScore()
{
	_score--;
}

int Player::getPosition()
{
	return _position;
}

void Player::setPosition(int position)
{
	_position = position;
}