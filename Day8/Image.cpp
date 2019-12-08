#pragma once
#include "Image.hpp"

#include <vector>
#include <string>
#include <sstream>

#include "Layer.hpp"

namespace Day8 {

	Image::Image(std::vector<Layer>& layers) {
		for (unsigned pix = 0; pix < _final.SIZE; pix++)
		{
			for (Layer& layer : layers)
			{
				_final.edit(pix, layer.getPix(pix));
				if (PixelType(_final.getPix(pix)) != PixelType::TRANSPARENT) {
					break;
				}
			}
		}
	}

	std::string Image::render() const {
		std::stringstream pics;
		pics << std::endl << std::endl;
		for (unsigned int h = 0; h < _final.HEIGHT; h++) {
			for (unsigned int w = 0; w < _final.WIDTH; w++) {
				char pixel = 0;
				switch (PixelType(_final.getPix(h * _final.WIDTH + w))) {
				case PixelType::BLACK:
					pixel = ' ';
					break;
				case PixelType::WITH:
					pixel = 219;
					break;
				default:
					pixel = 178;
					break;
				}
				pics << pixel;
			}
			pics << std::endl;
		}
		return pics.str();
	}
}