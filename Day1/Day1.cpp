#include <iostream>
#include <fstream>

#include "Day1.hpp"

namespace Day1 {

	void TheTyrannyOfTheRocketEquation::process() {
		this->_solution.setName("--- Day 1: The Tyranny of the Rocket Equation ---");
		this->_solution.setDescription1("The sum of the fuel requirements:");
		this->_solution.setDescription2("The sum of the fuel requirements for all of the modules on your spacecraft:");

		auto inputV = this->getInputInVector<int>();

		int part1 = 0;
		int part2 = 0;
		for (int currMass : inputV)
		{
			part1 += this->calcFuelRequirements(currMass);
			part2 += this->calcFuelRequirements(currMass, true);
		}

		_solution.setPart1(part1);
		_solution.setPart2(part2);
	}

	int TheTyrannyOfTheRocketEquation::calcFuelRequirements(int mass, bool recursive) {
		int fuel = mass / 3 - 2;
		if (!recursive) return fuel;
		if (fuel > 0)
		{
			return fuel + calcFuelRequirements(fuel, recursive);
		}
		else
		{
			return 0;
		}
	}

};