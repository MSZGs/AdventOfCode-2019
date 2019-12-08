#pragma once
#include <istream>
#include <string>

namespace Day3 {

	class Command {
	public:
		enum class Types : char {
			UP = 'U',
			DOWN = 'D',
			LEFT = 'L',
			RIGHT = 'R'
		};

		Command() = default;
		const Types getType() const { return _command; }
		int getStepCount() const { return _stepCount; }
		friend std::istream& operator>>(std::istream& stream, Command& comm);

	private:
		char _command_char;
		Types _command;
		int _stepCount;
	};
};