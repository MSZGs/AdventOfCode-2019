#include "Wire.hpp"
#include <sstream>

namespace Day3 {

	void Wire::makePoints() {
		_points.clear();
		int curr_x = 0;
		int curr_y = 0;
		_points.push_back(iPoint(curr_x, curr_y));
		for (const Command& cmd : _commands) {
			switch (cmd.getType()) {

			case Command::Types::UP:
				curr_y += cmd.getStepCount();
				break;
			case Command::Types::DOWN:
				curr_y -= cmd.getStepCount();
				break;
			case Command::Types::LEFT:
				curr_x -= cmd.getStepCount();
				break;
			case Command::Types::RIGHT:
				curr_x += cmd.getStepCount();
				break;
			default:
				break;

			}
			_points.push_back(iPoint(curr_x, curr_y));
		}
	}

	void Wire::makeLines() {
		_lines.clear();
		iPoint first = _points[0];
		int distanceB = 0;
		for (auto it = _points.begin() + 1; it != _points.end(); it++) {
			Line line = Line(first, *it, distanceB);
			_lines.push_back(line);
			distanceB += line.length();
			first = *it;
		}
	}

	std::istream& operator>>(std::istream& stream, Wire& w) {
		std::string wireString;
		std::getline(stream, wireString);
		if (wireString.size() > 0) {
			std::stringstream wireStream(wireString);

			w._commands.clear();
			Command command;
			while (wireStream >> command) {
				w._commands.push_back(command);
			}

			w.makePoints();
			w.makeLines();
		};
		return stream;
	}
};