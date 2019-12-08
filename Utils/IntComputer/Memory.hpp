#pragma once
#include <vector>

namespace IntComputer {
	class Memory
	{
	private:
		std::vector<int> _memory;
		std::stringstream* _in;
		std::stringstream* _out;
		std::stringstream* _err;
		std::size_t _execPointer = 0;
		bool _abort = false;
		
		void validateMemAdress(int memAdress) const
		{
			if (memAdress >= _memory.size() && memAdress < 0)
			{
				throw Exeptions::ACCESS_VIOLATION;
			}
		}

	public:
		enum class Exeptions
		{
			ACCESS_VIOLATION
		};

		Memory(std::vector<int> mem) : _memory(mem.begin(), mem.end()) {
		};

		Memory(int memsize) { _memory.resize(memsize); };

		size_t size() { return _memory.size(); }

		int read(int memAdress) const
		{
			this->validateMemAdress(memAdress);
			return _memory[memAdress];
		}

		const int& operator[](int memAdress) const
		{
			this->validateMemAdress(memAdress);
			return _memory[memAdress];
		}

		int& operator[](int memAdress)
		{
			this->validateMemAdress(memAdress);
			return _memory[memAdress];
		}

		void write(int memAdress, int value)
		{
			this->validateMemAdress(memAdress);
			_memory[memAdress] = value;
		}

		std::size_t getExecPointer() const
		{
			return _execPointer;
		}

		void setExecPointer(std::size_t ptr)
		{
			_execPointer = ptr;
		}

		int next() {
			return this->read(_execPointer++);
		}

		void abort() {
			this->_abort = true;
		}

		bool end() {
			return this->_abort;
		}

		void setIO(std::stringstream& in, std::stringstream& out) {
			_in = &in;
			_out = &out;
		}

		std::stringstream &inStream() { return *_in; }
		std::stringstream &outStream() { return *_out; }
		std::stringstream &errorStream() { return *_err; };

	};

	class Parameter {
	public:
		enum class Type {
			POSITION = 0,
			IMMEDIATE = 1,
			DEFAULT = POSITION
		};

		Parameter(int value, Memory& mem, Type type = Type::DEFAULT) : _value{ value }, _type{ type }, _mem { mem } { }

		int operator*() const {
			if (_type == Type::POSITION) {
				return _mem.read(_value);
			}
			else if (_type == Type::IMMEDIATE)
			{
				return _value;
			}
		};

		int operator()() const {
			return _value;
		}

	private:
		int _value;
		Type _type;
		Memory& _mem;
	};

};