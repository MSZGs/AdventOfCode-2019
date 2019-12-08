#pragma once
#include "../Utils/Point.hpp"

namespace Day3 {
	class Intersection : public Point<int> {

	protected:
		int _distanceFromStart;

	public:
		Intersection(int x = 0, int y = 0, int d = 0) : Point(x, y) {
			_distanceFromStart = d;
		};

		Intersection(Point p, int d = 0) : Intersection(p.x(), p.y(), d) {};

		int getDistanceFromStart() const { return _distanceFromStart; }

		int manhattanDistance(const Intersection& other) const {
			return abs(_x - other._x) + abs(_y + other._y);
		}

		static int manhattanDistance(const Intersection& a, const Intersection& b) {
			return abs(a._x - b._x) + abs(a._y + b._y);
		}
	};
};