#pragma once

#include "wavelets.h"
#include <vector>
#include <functional>

namespace wnn
{
	const double TRANS_SCALE = 0.5;
	const double DIL_SCALE = 0.2;
	class Wavelon
	{
	public:
		Wavelon(int dim);

		void init(double min, double max);

		double process(std::vector<double> x);

	private:
		std::function<double(double)> motherWavelet;
		std::vector<double> trans;
		std::vector<double> dilate;
	};
}