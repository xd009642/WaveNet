#pragma once

#include "layer.h"
#include <vector>

namespace wnn
{

	class Network
	{
	public:
		Network(int inputs, int wavelons);
		double process(std::vector<double> in);
	private:
		wnn::WavelonLayer wavelons;
		wnn::OutputLayer out;
	};

}