#pragma once
#include <algorithm>
#include <istream>
#include <sstream>
#include <map>

#include "../Utils/Day.hpp"

namespace Day8 {
	class SpaceImageFormat : public Day {
	private:
		void process() override;

	public:
		SpaceImageFormat(std::string inputFile) : Day(inputFile) { }
	};
};
typedef Day8::SpaceImageFormat SpaceImageFormat;
