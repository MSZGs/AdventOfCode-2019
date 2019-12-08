#include "Day6.hpp"

namespace Day6 {

	void UniversalOrbitMap::process() {
		this->_solution.setName("--- Day 6: Universal Orbit Map ---");
		this->_solution.setDescription1("The total number of direct and indirect orbits:");
		this->_solution.setDescription2("The minimum number of orbital transfers required:");

		auto inpV = this->getInputInVector<OrbitMapData>();

		for (OrbitMapData& dat : inpV)
		{
			_tree->addData(dat);
		}
		_tree->setRoot("COM");

		this->_solution.setPart1(countOrbits());
		this->_solution.setPart2(orbitalTransfersRequired("SAN", "YOU"));
	}

	int UniversalOrbitMap::orbitalTransfersRequired(const std::string& from, const std::string& to) const {
		return _tree->distance(_tree->getLeaf(from), _tree->getLeaf(to)) - 2;
	}

	int UniversalOrbitMap::countOrbits() const {
		const Leaf* l = _tree->getRoot();
		int sum = countOrbitsReqursion(l, 0);
		return sum;
	}

	int UniversalOrbitMap::countOrbitsReqursion(const Leaf* leaf, const int sum) const {
		if (leaf->haveChildren()) {
			int isum = sum;
			for (const Leaf* l : leaf->getChildren()) {
				isum += countOrbitsReqursion(l, sum + 1);
			}
			return isum;
		}
		else {
			return sum;
		}
	}
};