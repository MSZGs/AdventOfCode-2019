#pragma once
#include <algorithm>

#include "../Utils/Point.hpp"

#include "Intersection.hpp"

namespace Day3 {
	class Line {
	public:
		Line(const iPoint start, const iPoint end, int distance = 0) {
			_p1 = start;
			_p2 = end;
			_distanceBefore = distance;
		}

		bool onLine(iPoint p) const {
			return (std::min(_p1.x(), _p2.x()) <= p.x()) &&
				   (std::max(_p1.x(), _p2.x()) >= p.x()) &&
				   (std::min(_p1.y(), _p2.y()) <= p.y()) &&
				   (std::max(_p1.y(), _p2.y()) >= p.y());
		}

		//! The 2 line have to be perpendicular
		Intersection intersection(const Line& other) const{
			iPoint p(0, 0);
			int d = 0;

			if (_p1.x() == _p2.x() && other._p1.y() == other._p2.y()) {
				p = iPoint(_p1.x(), other._p1.y());
				int d1 = _distanceBefore + p.distance(_p1);
				int d2 = other._distanceBefore + p.distance(other._p1);
				d = d1 + d2;
			}

			if (_p1.y() == _p2.y() && other._p1.x() == other._p2.x()) {
				p = iPoint(other._p1.x(), _p1.y());
				int d1 = _distanceBefore + p.distance(_p1);
				int d2 = other._distanceBefore + p.distance(other._p1);
				d = d1 + d2;
			}

			return Intersection(p, d);
		}

		int length() const {
			return static_cast<int>(std::sqrt((_p1.x() - _p2.x()) * (_p1.x() - _p2.x()) +
											  (_p1.y() - _p2.y()) * (_p1.y() - _p2.y())));
		}

		int getDistanceBefore() const {
			return _distanceBefore;
		}

	private:
		iPoint _p1;
		iPoint _p2;
		int _distanceBefore;
	};
};
