#pragma once

#include "Wavelon.h"


namespace wnn
{
	class Layer
	{

	private:
		std::vector<Wavelon> wavelons;
		std::vector<double> weights;
	};
}