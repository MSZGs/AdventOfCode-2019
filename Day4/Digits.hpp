#pragma once
#include <iterator>

namespace Day4 {

	template<int NUMSYS = 10>
	class Digits {
	private:
		int _number;
		static constexpr int numeralSystem = NUMSYS;
	public:
		Digits(int number) : _number{ number } { }

		bool digitsNeverDecrease(bool strict = false) const;
		std::vector<int> digitCount() const;

		class iterator : public std::iterator<std::input_iterator_tag, int, int, const int*, int > {

		private:
			int _num;

		public:
			explicit iterator(int num) : _num(num) {}
			iterator& operator++() { _num /= NUMSYS; return *this; }
			iterator operator++(int) { iterator retval = *this; ++(*this); return retval; }
			bool operator==(iterator other) const { return _num == other._num; }
			bool operator!=(iterator other) const { return !(*this == other); }
			reference operator*() const { return _num % NUMSYS; }
		};

		iterator begin() const { return iterator(_number); }
		iterator end() const { return iterator(0); }
	};

	template<int NUMSYS>
	bool Digits<NUMSYS>::digitsNeverDecrease(bool strict) const {
		int max = NUMSYS;
		for (auto digit : *this) {
			if (strict ? digit >= max : digit > max) {
				return false;
			}
			max = digit;
		}
		return true;
	}

	template<int NUMSYS>
	std::vector<int> Digits<NUMSYS>::digitCount() const {
		std::vector<int> dc(NUMSYS, 0);
		for (auto i : *this) {
			dc[i]++;
		}
		return dc;
	}


};