#include "Day4.hpp"

namespace Day4 {
	void SecureContainer::process() {
		this->_solution.setName("--- Day 4: Secure Container ---");
		this->_solution.setDescription1("Different passwords within the range given in your puzzle input (criteria #1):");
		this->_solution.setDescription2("Different passwords within the range given in your puzzle input (criteria #2):");

		auto rangeVec = this->getInputInVector<Range>();
		Range& range = rangeVec[0];

		int c1 = 0;
		int c2 = 0;

		for (int number : range) {
			Digits<> digits = Digits<10>(number);
			if (digits.digitsNeverDecrease()) {
				auto nc = digits.digitCount();
				if (hasPair(nc)) { c1++; }
				if (hasPair(nc, true)) { c2++; }
			}
		}

		this->_solution.setPart1(c1);
		this->_solution.setPart2(c2);
	}

	bool SecureContainer::hasPair(std::vector<int>& numcounts, bool strict) const {
		for (int c : numcounts) {
			if (strict ? c == 2 : c >= 2) {
				return true;
			}
		}
		return false;
	}

};