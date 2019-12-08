#pragma once
#include "Day5.hpp"

#include "../Utils/IntComputer.hpp"

namespace Day5 {
	void SunnyWithAChanceOfAsteroids::process() {
		this->_solution.setName("--- Day 5: Sunny with a Chance of Asteroids ---");
		this->_solution.setDescription1("The Diagnostic code:");
		this->_solution.setDescription2("The diagnostic code for system ID 5:");

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

		auto inpV = this->getInputInVector<int>(',');

		intComputer.loadProgram(inpV);
		intComputer.input() << 1;
		intComputer.run();
		int result;
		intComputer.output() >> result;
		this->_solution.setPart1(result);

		intComputer.clearIO();
		intComputer.loadProgram(inpV);
		intComputer.input() << 5;
		intComputer.run();
		int result2;
		intComputer.output() >> result2;
		this->_solution.setPart2(result2);
	}

};
