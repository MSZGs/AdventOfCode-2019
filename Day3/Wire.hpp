#pragma once
#include <vector>
#include <istream>

#include "Line.hpp"
#include "Command.hpp"

namespace Day3 {

	class Wire {
	public:
		Wire() { }

		const std::vector<Line>& getLines() const { return _lines; }
		friend std::istream& operator>>(std::istream& stream, Wire& w);

	private:
		std::vector<Command> _commands;
		std::vector<iPoint> _points;
		std::vector<Line> _lines;

		void makePoints();
		void makeLines();

	};
};