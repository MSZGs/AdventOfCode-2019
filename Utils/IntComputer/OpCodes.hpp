#pragma once
#include "Memory.hpp"

namespace IntComputer {
	typedef unsigned int uint;

	class Opcode
	{
	protected:
		const uint _argsCount;
		const int _intCode;

	public:
		typedef std::vector<Parameter> Args;
		Opcode(int intCode, uint argsCount = 0) : _argsCount{ argsCount }, _intCode{ intCode } { }
		virtual void exec(Memory&, const Args&) = 0;
		virtual uint argsNeeded() const { return this->_argsCount; };
		int intCode() const { return _intCode; }
	};

	namespace Opcodes {

		class Adding : public Opcode {
		public:
			Adding() : Opcode(1, 3) {}

			void exec(Memory& memory, const Args& args) override {
				int result = (*args[0]) + (*args[1]);
				memory.write(args[2](), result);
			}
		};

		class Multiplying : public Opcode
		{
		public:
			Multiplying() : Opcode(2, 3) {};

			void exec(Memory& memory, const Args& args) override {
				int result = (*args[0]) * (*args[1]);
				memory.write(args[2](), result);
			}
		};
		class Abort : public Opcode
		{
		public:
			Abort() : Opcode(99, 0) {}

			void exec(Memory& memory, const Args& args) override {
				memory.abort();
			}
		};

		class Input : public Opcode
		{
		public:
			Input() : Opcode(3, 1) {};

			void exec(Memory& memory, const Args& args) override {
				int result;
				memory.inStream() >> result;
				memory.write(args[0](), result);
			}
		};

		class Output : public Opcode
		{
		public:
			Output() : Opcode(4, 1) {};

			void exec(Memory& memory, const Args& args) override {
				int result = memory.read(args[0]());
				memory.outStream() << result << " ";
			}
		};

		class JumpIfTrue : public Opcode
		{
		public:
			JumpIfTrue() : Opcode(5, 2) {};

			void exec(Memory& memory, const Args& args) override {
				if (*args[0]) {
					memory.setExecPointer(*args[1]);
				}
			}
		};

		class JumpIfFalse : public Opcode
		{
		public:
			JumpIfFalse() : Opcode(6, 2) {};

			void exec(Memory& memory, const Args& args) override {
				if (!*args[0]) {
					memory.setExecPointer(*args[1]);
				}
			}
		};

		class LessThan : public Opcode
		{
		public:
			LessThan() : Opcode(7, 3) {};

			void exec(Memory& memory, const Args& args) override {
				memory.write(args[2](), *args[0] < *args[1] ? 1 : 0);
			}
		};

		class Equals : public Opcode
		{
		public:
			Equals() : Opcode(8, 3) {};

			void exec(Memory& memory, const Args& args) override {
				memory.write(args[2](), *args[0] == *args[1] ? 1 : 0);
			}
		};

	} // namespace Opcodes

}

