#pragma once
#include <map>

#include "Memory.hpp"
#include "OpCodes.hpp"
namespace IntComputer {
	typedef unsigned int uint;

	class Processor {
	private:
		std::map<int, Opcode*> _supportedCommands;
		std::vector<Parameter> _cache;

	public:
		enum class Exceptions {
			UNKNOWN_COMMAND
		};

		void addCommand(Opcode* cmd) {
			_supportedCommands.insert(std::make_pair(cmd->intCode(), cmd));
		}

		Processor() {}

		~Processor() {
			for (auto cmd : _supportedCommands) {
				delete cmd.second;
			}
		}

		void process(Memory& mem) {
			int code = mem.next();
			int intCode = code % 100;
			code /= 100;

			_cache.clear();

			auto cmd = _supportedCommands.find(intCode);
			if (cmd == _supportedCommands.end()) {
				throw Exceptions::UNKNOWN_COMMAND;
			}
			Opcode* codec = cmd->second;

			int argcount = codec->argsNeeded();
			for (int i = 0; i < argcount; i++) {
				int value = mem.next();
				_cache.push_back(Parameter(value, mem, Parameter::Type(code % 10)));
				code /= 10;
			}
			codec->exec(mem, _cache);
		}
	};
}
