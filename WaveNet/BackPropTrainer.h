#pragma once

#include "network.h"
#include <cmath>

namespace wnn
{
	class BackPropTrainer
	{
		void train(Network& network, std::vector<double> data, double label);
	};
}