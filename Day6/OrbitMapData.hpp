#pragma once
#include <string>
#include <sstream>

namespace Day6 {

	class OrbitMapData {
	private:
		std::string _center;
		std::string _object;

	public:
		OrbitMapData() = default;
		const std::string& getCenter() const { return _center; }
		const std::string& getObject() const { return _object; }

		friend std::istream& operator>>(std::istream& stream, OrbitMapData& comm) {
			std::string line;
			std::getline(stream, line);
			if (line.size() > 0) {
				std::stringstream s(line);
				std::getline(s, comm._center, ')');
				s >> comm._object;
			}
			return stream;
		}
	};
};
