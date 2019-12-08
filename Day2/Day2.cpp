#pragma once
#include "Day2.hpp"
#include <map>

namespace Day2 {

	void ProgramAlarm::process() {
		this->_solution.setName("--- Day 2: 1202 Program Alarm ---");
		this->_solution.setDescription1("The value that left at position 0 after the program halts:");
		this->_solution.setDescription2("The noun and verb that cause the program to produce the output 19690720 (100 * noun + verb):");

		auto inpV = this->getInputInVector<int>(',');

		IntComputer::Computer intComputer;

		std::vector<IntComputer::Opcode*> commands;
		commands.push_back(new IntComputer::Opcodes::Adding());
		commands.push_back(new IntComputer::Opcodes::Multiplying());
		commands.push_back(new IntComputer::Opcodes::Abort());
		intComputer.addCommands(commands);

		std::vector<int> teszt = { 2,3,0,3,99 };

		intComputer.loadProgram(inpV);
		intComputer.editMemory(1, 12);
		intComputer.editMemory(2, 2);
		intComputer.run();
		this->_solution.setPart1(intComputer.readMemory(0));

		for (int noun = 0; noun <= 99; noun++) {
			for (int verb = 0; verb <= 99; verb++) {
				intComputer.loadProgram(inpV);
				intComputer.editMemory(1, noun);
				intComputer.editMemory(2, verb);
				intComputer.run();
				if (19690720 == intComputer.readMemory(0)) {
					this->_solution.setPart2(100 * noun + verb);
					break;
				}
			}
		}
	}
};