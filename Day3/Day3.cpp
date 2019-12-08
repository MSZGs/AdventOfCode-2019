#include "Day3.hpp"

namespace Day3 {

	void CrossedWires::process() {
		this->_solution.setName("--- Day 3: Crossed Wires ---");
		this->_solution.setDescription1("The Manhattan distance from the central port to the closest intersection:");
		this->_solution.setDescription2("The fewest combined steps the wires must take to reach an intersection:");

		auto inputW = this->getInputInVector<Wire>();
		Wire& w1 = inputW[0];
		Wire& w2 = inputW[1];

		auto intersec = this->makeIntersections(w1, w2);

		Intersection center(0, 0);
		int minManhattanDistance = std::min_element(intersec.begin(), intersec.end(),
			[center](Intersection& a, Intersection& b) {
			return a.manhattanDistance(center) < b.manhattanDistance(center);
		})->manhattanDistance(center);

		int minDistanceFromStart = std::min_element(intersec.begin(), intersec.end(),
			[](Intersection& a, Intersection& b) {
			return a.getDistanceFromStart() < b.getDistanceFromStart();
		})->getDistanceFromStart();

		this->_solution.setPart1(minManhattanDistance);
		this->_solution.setPart2(minDistanceFromStart);
	}

	std::vector<Intersection> CrossedWires::makeIntersections(Wire& w1, Wire& w2) {
		std::vector<Intersection> intersections;
		for (auto& line1 : w1.getLines()) {
			for (auto& line2 : w2.getLines()) {
				Intersection intersect = line1.intersection(line2);
				if (line1.onLine(intersect) &&
					line2.onLine(intersect) &&
					(intersect.x() != 0 || intersect.y() != 0)){

					intersections.push_back(intersect);
				}
			}
		}
		return intersections;
	}

};