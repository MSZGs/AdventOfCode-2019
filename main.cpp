#include <iostream>
#include <string>
#include "Utils/Day.hpp"
#include "Day1/Day1.hpp"
#include "Day2/Day2.hpp"
#include "Day3/Day3.hpp"
#include "Day4/Day4.hpp"
#include "Day5/Day5.hpp"
#include "Day6/Day6.hpp"
#include "Day7/Day7.hpp"
#include "Day8/Day8.hpp"

int main() {
	std::vector<Day*> days;
	days.push_back(new TheTyrannyOfTheRocketEquation("Inputs/inputDay1"));
	days.push_back(new ProgramAlarm("Inputs/inputDay2"));
	days.push_back(new CrossedWires("Inputs/inputDay3"));
	days.push_back(new SecureContainer("Inputs/inputDay4"));
	days.push_back(new SunnyWithAChanceOfAsteroids("Inputs/inputDay5"));
	days.push_back(new UniversalOrbitMap("Inputs/inputDay6"));
	days.push_back(new AmplificationCircuit("Inputs/inputDay7"));
	days.push_back(new SpaceImageFormat("Inputs/inputDay8"));

	for (Day* day : days) {
		day->doMagic();
		std::cout << day->getSolution() << std::endl;
		delete day;
	}

	std::cin.get();
	return 0;
}