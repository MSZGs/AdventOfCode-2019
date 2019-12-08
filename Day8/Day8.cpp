#pragma once
#include "Day8.hpp"

#include "Layer.hpp"
#include "Image.hpp"

namespace Day8 {

	void SpaceImageFormat::process() {
		this->_solution.setName("--- Day 8: Space Image Format ---");
		this->_solution.setDescription1("The number of 1 digits multiplied by the number of 2 digit:");
		this->_solution.setDescription2("Message is produced after decoding your image:");

		auto inpV = this->getInputInVector<Layer>();

		auto min = std::min_element(inpV.begin(), inpV.end(), [](Layer& a, Layer& b) { return a.count(0) < b.count(0); });
		this->_solution.setPart1(min->count(1) * min->count(2));

		Image n = Image(inpV);
		this->_solution.setPart2(n.render());
	}
};
