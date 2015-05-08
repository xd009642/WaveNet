#pragma once

#include <cmath>

namespace wnn
{
	/*
	IMPLEMENTATION OF WAVELET FUNCTIONS
	*/

	//Also known as the "Mexican Hat" wavelet
	const auto ricker = [](double z)
	{
		return (1 - pow(z, 2))*exp(-0.5*pow(z, 2));
	};


	const auto morlet = [](double z)
	{
		return exp(-0.5*pow(z, 2))*cos(5*z);
	};


	const auto haar = [](double z)
	{
		if (z >= 0 && z < 0.5)
			return 1.0;
		else if (z >= 0.5 && z < 1.0)
			return -1.0;
		return 0.0;
	};
}