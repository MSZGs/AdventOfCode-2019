#pragma once
#include "../Utils/Day.hpp"

namespace Day5 {

	class SunnyWithAChanceOfAsteroids : public Day {
	private:
		void process() override;
	public:
		SunnyWithAChanceOfAsteroids(std::string inputFile) : Day(inputFile) { }
	};
};
typedef Day5::SunnyWithAChanceOfAsteroids SunnyWithAChanceOfAsteroids;