#ifndef Player_h
#define Player_h

#include "Arduino.h"

class Player
{
	public:
		Player(int score, int position);
		int _score;
		int _position;
		int getScore();
		int getPosition();
		void setPosition(int position);
		void setScore(int position);
		void incrementScore();
		void decrementScore();
};
#endif