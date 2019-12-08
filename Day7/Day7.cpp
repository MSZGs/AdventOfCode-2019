#pragma once
#include "Day7.hpp"

#include <algorithm>

#include "../Utils/IntComputer.hpp"

namespace Day7 {

	void AmplificationCircuit::process() {
		this->_solution.setName("--- Day 7: Amplification Circuit ---");
		this->_solution.setDescription1("The highest signal that can be sent to the thrusters:");
		this->_solution.setDescription2("???");

		auto inpV = this->getInputInVector<int>(',');

		IntComputer::Computer intComputer;
		std::vector<IntComputer::Opcode*> commands;
		commands.push_back(new IntComputer::Opcodes::Adding());
		commands.push_back(new IntComputer::Opcodes::Multiplying());
		commands.push_back(new IntComputer::Opcodes::Abort());
		commands.push_back(new IntComputer::Opcodes::Input());
		commands.push_back(new IntComputer::Opcodes::Output());
		commands.push_back(new IntComputer::Opcodes::JumpIfTrue());
		commands.push_back(new IntComputer::Opcodes::JumpIfFalse());
		commands.push_back(new IntComputer::Opcodes::LessThan());
		commands.push_back(new IntComputer::Opcodes::Equals());
		intComputer.addCommands(commands);
		std::vector<int> test{ 3, 26, 1001, 26, -4, 26, 3, 27, 1002, 27, 2, 27, 1, 27, 26,
			27, 4, 27, 1001, 28, -1, 28, 1005, 28, 6, 99, 0, 0, 5 };

		std::vector<int> phaseSetting = { 0,1,2,3,4 };
		int max = 0;
		do {
			int data = 0;
			for (auto it = phaseSetting.begin(); it != phaseSetting.end(); it++) {
				intComputer.loadProgram(inpV);
				intComputer.input() << *it << " " << data << " ";
				intComputer.run();
				intComputer.output() >> data;
				intComputer.clearIO();
			}
			if (data > max) {
				max = data;
			}
		} while (std::next_permutation(phaseSetting.begin(), phaseSetting.end()));
		this->_solution.setPart1(max);


		phaseSetting = { 9,8,7,6,5 };
		int max2 = 0;
		do {
			int data = 0;
			for (auto it = phaseSetting.begin(); it != phaseSetting.end(); it++) {
				intComputer.loadProgram(test);
				intComputer.input() << *it << " " << data << " ";
				intComputer.run();
				intComputer.output() >> data;
				intComputer.clearIO();
			}
			if (data > max2) {
				max2 = data;
			}
		} while (std::next_permutation(phaseSetting.begin(), phaseSetting.end()));
		this->_solution.setPart2(max2);
	}
};
typedef Day7::AmplificationCircuit AmplificationCircuit;