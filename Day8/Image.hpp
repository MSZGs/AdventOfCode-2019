#pragma once
#include "Layer.hpp"

namespace Day8 {
	class Image {
	public:
		enum class PixelType {
			BLACK = 0,
			WITH = 1,
			TRANSPARENT = 2,
		};

		Image(std::vector<Layer>& layers);
		std::string render() const;

	private:
		Layer _final;
	};
}