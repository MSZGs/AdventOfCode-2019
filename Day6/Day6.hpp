#pragma once
#include <map>
#include <string>
#include <sstream>

#include "../Utils/Day.hpp"

#include "Tree.hpp"

namespace Day6 {
	class UniversalOrbitMap : public Day {
	private:

		Tree* _tree;

		int orbitalTransfersRequired(const std::string& from, const std::string& to) const;
		int countOrbits() const;
		int countOrbitsReqursion(const Leaf* leaf, const int sum) const;
		void process() override;

	public:
		UniversalOrbitMap(std::string inputFile) : Day(inputFile) {
			_tree = new Tree;
		}
		~UniversalOrbitMap() { delete _tree; };
	};
}

typedef Day6::UniversalOrbitMap UniversalOrbitMap;