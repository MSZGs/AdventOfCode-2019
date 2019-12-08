#pragma once
#include <chrono>
#include <string>

class Solution {
protected:
	typedef std::chrono::duration<double> duration;
	long int _part1;
	long int _part2;
	std::string _part1_str;
	std::string _part2_str;
	std::string _desc1;
	std::string _desc2;
	std::string _name;
	duration _runTime;

public:
	Solution() : _part1{ -1 }, _part2{ -1 }, _runTime{ 0 } {};
	
	const long int getPart1() const { return _part1; }
	const long int getPart2() const { return _part2; }
	const std::string& getDescription1() const { return _desc1; }
	const std::string& getDescription2() const { return _desc2; }
	const std::string& getName() const { return _name; }
	const duration& getRunTime() const{ return _runTime; }

	void setPart1(long int value) { _part1 = value;	}
	void setPart2(long int value) {	_part2 = value; }
	void setPart2(std::string value) { _part2_str = value; }
	void setDescription1(const char* s) { _desc1 = std::string(s); }
	void setDescription1(std::string& d) { _desc1 = d; }
	void setDescription2(const char* s) { _desc2 = std::string(s); }
	void setDescription2(std::string& d) { _desc2 = d; }
	void setName(const char* s) { _name = std::string(s); }
	void setName(std::string& d) { _name = d; }
	void setRunTime(duration time) { _runTime = time; }

	friend std::ostream& operator<<(std::ostream& stream,const Solution& s) {
		stream << s._name << std::endl;
		stream << s._desc1 << " " << s._part1 << s._part1_str << std::endl;
		stream << s._desc2 << " " << s._part2 << s._part2_str << std::endl;
		return stream;
	}
};