#pragma once
#include "../Utils/Day.hpp"

namespace Day1 {

	class TheTyrannyOfTheRocketEquation : public Day {
	private:
		void process() override;
		int calcFuelRequirements(int mass, bool recursive = false);

	public:
		TheTyrannyOfTheRocketEquation(std::string inputFile) : Day(inputFile) { }
	};

};
typedef Day1::TheTyrannyOfTheRocketEquation TheTyrannyOfTheRocketEquation;