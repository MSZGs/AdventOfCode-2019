#pragma once
template<long FROM, long TO>
class Range {
public:
	class iterator : public std::iterator<std::input_iterator_tag,long,long,const long*,long> {
		long num = FROM;
	public:
		explicit iterator(long _num = 0) : num(_num) {}
		iterator& operator++() { num = TO >= FROM ? num + 1 : num - 1; return *this; }
		iterator operator++(int) { iterator retval = *this; ++(*this); return retval; }
		bool operator==(iterator other) const { return num == other.num; }
		bool operator!=(iterator other) const { return !(*this == other); }
		reference operator*() const { return num; }
	};
	iterator begin() { return iterator(FROM); }
	iterator end() { return iterator(TO >= FROM ? TO + 1 : TO - 1); }
};