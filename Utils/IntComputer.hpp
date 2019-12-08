#pragma once
#include <vector>
#include <sstream>
#include <map>

#include "IntComputer/Memory.hpp"
#include "IntComputer/OpCodes.hpp"
#include "IntComputer/Processor.hpp"

namespace IntComputer {
	typedef unsigned int uint;

	class Computer
	{
	protected:
		Memory* _memory = nullptr;
		std::stringstream* _input;
		std::stringstream* _output;
		Processor* _processor;

	public:
		Computer() : _memory{ nullptr }  {
			_processor = new Processor();
			_input = new std::stringstream();
			_output = new std::stringstream();
		};

		~Computer()	{
			delete _memory;
			delete _processor;
			delete _input;
			delete _output;
		}

		void addCommands(std::vector<Opcode*> coms) {
			for (Opcode* code : coms) {
				this->_processor->addCommand(code);
			}
		};

		void loadProgram(std::vector<int>& program)	{
			if (_memory != nullptr)	{
				delete _memory;
			}
			_memory = new Memory(program);
			_memory->setIO(*_input, *_output);
		}

		void run()	{
			while (!_memory->end())	{
				_processor->process(*_memory);
			}
		}

		void editMemory(uint adress, int value) {
			_memory->write(adress, value);
		}

		int readMemory(uint adress) const {
			return _memory->read(adress);
		}

		std::stringstream& input() {
			return *_input;
		}

		std::stringstream& output()	{
			return *_output;
		}

		void clearIO() {
			_input = new std::stringstream();
			_output = new std::stringstream();
			_memory->setIO(*_input, *_output);
		}
	};
};