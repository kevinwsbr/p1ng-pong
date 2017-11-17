#ifndef Ball_h
#define Ball_h

#include "Arduino.h"

class Ball
{
	public:
		Ball(int x, int y, int headingX, int headingY);
		int _x;
		int _y;
		int _headingX;
		int _headingY;

		int getX();
		int getY();
		void decrementX();
		void decrementY();
		void incrementX();
		void incrementY();
		void setX(int x);
		void setY(int y);
		int getHeadingX();
		int getHeadingY();
		void setHeadingX(int x);
		void setHeadingY(int y);
		void invertHeadingX();
		void invertHeadingY();
};
#endif