#pragma once
#include <vector>

#include "../Utils/Day.hpp"

#include "Range.hpp"
#include "Digits.hpp"

namespace Day4 {
	class SecureContainer : public Day {
	private:
		void process() override;
		bool hasPair(std::vector<int>& numcounts, bool strict = false) const;

	public:
		SecureContainer(std::string inputFile) : Day(inputFile) { }
	};

}

typedef Day4::SecureContainer SecureContainer;