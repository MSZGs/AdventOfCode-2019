#pragma once
#include <map>

#include "../Utils/Day.hpp"
#include "../Utils/IntComputer.hpp"

namespace Day2 {

	class ProgramAlarm : public Day {
	private:
		void process() override;
	public:
		ProgramAlarm(std::string inputFile) : Day(inputFile) { }
	};

};
typedef Day2::ProgramAlarm ProgramAlarm;