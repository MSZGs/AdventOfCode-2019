#pragma once
#include <iterator>

namespace Day4 {

	struct Range {
		int from;
		int to;

		class iterator : public std::iterator<std::input_iterator_tag, int, int, const int*, int > {
			int _from;
			int _to;
			int _num;

		public:
			explicit iterator(int from, int to) : _from(from), _to{ to }, _num{ from } {}
			explicit iterator(int from, int to, int num) : _from(to), _to{ to }, _num{ num } {}
			iterator& operator++() { _num++; return *this; }
			iterator operator++(int) { iterator retval = *this; ++(*this); return retval; }
			bool operator==(iterator other) const { return _num == other._num; }
			bool operator!=(iterator other) const { return !(*this == other); }
			reference operator*() const { return _num; }
		};

		iterator begin() { return iterator(from, to); }
		iterator end() { return iterator(from, to, to); }

		friend std::istream& operator>>(std::istream& stream, Range& r) {
			std::string froms;
			std::getline(stream, froms, '-');
			if (froms.size() > 0) {
				r.from = std::atoi(froms.c_str());
				stream >> r.to;
			}
			return stream;
		}

	};

};