/*
 * Point.h
 *
 *  Created on: Oct 27, 2017
 *      Author: yael
 */

#ifndef POINT_H_
#define POINT_H_

class Point{

public:
	Point(int x, int y)
    {
		this->x = x;
		this->y = y;
	};

	int getX() const
	{
		return x;
	}

	int getY() const
	{
		return y;
	}
	bool operator == (const Point& lhs)
	{
		return lhs.x == x && lhs.y == y;
	}

private:
	int x;
	int y;
};





#endif /* POINT_H_ */
