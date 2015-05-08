#include "Wavelon.h"


wnn::Wavelon::Wavelon(int dim):
motherWavelet(ricker),
trans(std::vector<double>(TRANS_SCALE, dim)),
dilate(std::vector<double>(DIL_SCALE, dim))
{

}

void wnn::Wavelon::init(double min, double max)
{
	std::fill(std::begin(trans), std::end(trans), TRANS_SCALE*(max - min));
	std::fill(std::begin(dilate), std::end(dilate), DIL_SCALE*(max - min));
}

double wnn::Wavelon::process(std::vector<double> x)
{
	double result = 1;
	for (int i = 0; i < trans.size(); i++)
	{
		if (i >= x.size())
			x.push_back(0.0);
		result *= motherWavelet((x[i] - trans[i]) / dilate[i]);
	}
	return result;
}