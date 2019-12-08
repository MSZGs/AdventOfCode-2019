#include "Command.hpp"

namespace Day3 {

	std::istream& operator>>(std::istream& stream, Command& comm) {
		std::string commandString;
		std::getline(stream, commandString, ',');
		if (commandString.size() > 1) {
			comm._command_char = commandString[0];
			comm._command = Command::Types(comm._command_char);
			commandString.erase(0, 1);
			comm._stepCount = std::stoi(commandString);
		}
		return stream;
	}

};