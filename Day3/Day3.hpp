#pragma once
#include <sstream>

#include "../Utils/Day.hpp"
#include "../Utils/Solution.hpp"

#include "Intersection.hpp"
#include "Wire.hpp"

namespace Day3 {

	class CrossedWires : public Day {
	private:
		void process() override;
		std::vector<Intersection> makeIntersections(Wire& w1, Wire& w2);

	public:
		CrossedWires(std::string inputFile) : Day(inputFile) { }
	};
};

typedef Day3::CrossedWires CrossedWires;