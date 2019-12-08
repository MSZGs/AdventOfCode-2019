#pragma once
#include "../Utils/Day.hpp"

namespace Day7 {

	class AmplificationCircuit : public Day {
	private:
		void process() override;
	public:
		AmplificationCircuit(std::string inputFile) : Day(inputFile) { }
	};
};
typedef Day7::AmplificationCircuit AmplificationCircuit;