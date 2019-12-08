#pragma once
#include "Layer.hpp"

#include <vector>
#include <map>

namespace Day8 {
	void Layer::clear() {
		_counts.clear();
		_pics.clear();
	}

	void Layer::preProcess() {
		_counts.clear();
		for (int p : _pics) {
			auto it = _counts.find(p);
			if (it == _counts.end()) {
				_counts.insert(std::make_pair(p, 1));
			}
			else {
				it->second++;
			}
		}
	}

	int Layer::count(int num) const {
		auto it = _counts.find(num);
		if (it == _counts.end()) {
			return 0;
		}
		else {
			return it->second;
		}
	}
};
