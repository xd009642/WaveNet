#pragma once

#include "layer.h"
#include <vector>

namespace wnn
{

	class Network
	{
	public:
		void addInputLayer(int in, int out);
		void addLayer(int in, int out);
	private:
		std::vector<wnn::Layer> layers;
	};

}