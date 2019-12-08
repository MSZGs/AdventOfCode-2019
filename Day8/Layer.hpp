#pragma once
#include <istream>
#include <vector>
#include <map>

namespace Day8 {
	class Layer {
	public:
		static constexpr unsigned int HEIGHT = 6;
		static constexpr unsigned int WIDTH = 25;
		static constexpr unsigned int SIZE = WIDTH * HEIGHT;

		Layer() { _pics.resize(SIZE); };

		void clear();
		void preProcess();
		int count(int num) const;
		void edit(std::size_t pix, int color) {	this->_pics[pix] = color; }
		int getPix(std::size_t pix) const {	return this->_pics[pix]; }

		friend std::istream& operator>>(std::istream& stream, Layer& img) {
			img.clear();
			char tmp;
			for (int i = 0; i < img.SIZE; i++) {
				stream >> tmp;
				img._pics.push_back(tmp - '0');
			}
			img.preProcess();
			return stream;
		}

	private:
		std::vector<int> _pics;
		std::map<int, int> _counts;
	};
};
