#pragma once
#include <chrono>
#include <fstream>
#include <vector>
#include "Solution.hpp"

class Day {
private:
	std::ifstream _input;

protected:
	Solution _solution;
	virtual void process() = 0;
	
	std::ifstream &inputStream() {
		return _input;
	}

	template<typename VecType>
	std::vector<VecType> getInputInVector() {
		std::vector<VecType> inp;

		VecType data;

		while (_input >> data) {
			inp.push_back(data);
		};

		return inp;
	}

	template<typename VecType>
	std::vector<VecType> getInputInVector(char delimiter) {
		std::vector<VecType> inp;
		VecType data;
		std::string n;
		while (std::getline(_input, n, delimiter)) {
			std::stringstream s(n);
			s >> data;
			inp.push_back(data);
		};
		return inp;
	}


	Day(std::string inputFile) {
		_input.open(inputFile);
	}

public:
	void doMagic() {
		auto start = std::chrono::system_clock::now();
		this->process();
		auto end = std::chrono::system_clock::now();
		_solution.setRunTime(end - start);
	}

    const Solution getSolution() const{
        return _solution;
    }

	virtual ~Day() {
		_input.close();
	}
};