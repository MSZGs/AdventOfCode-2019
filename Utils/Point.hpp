#pragma once
#include <cmath>

template<class T = double>
class Point
{
protected:
	T _x;
	T _y;

public:
	Point(T x = 0, T y = 0) : _x(x), _y(y)
	{
	}

	const T& x() const {
		return _x;
	}

	T& x(){
		return _x;
	}

	const T& y() const {
		return _y;
	}

	T& y() {
		return _y;
	}

	int distance(const Point& other)
	{
		return static_cast<int>(std::sqrt((_x - other._x) * (_x - other._x) +
										  (_y - other._y) * (_y - other._y)));
	}
};

typedef Point<int> iPoint;