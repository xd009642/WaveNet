#include "layer.h"



wnn::Layer::Layer(int in, int out):
wavelons(out, wnn::Wavelon(in)),
weights(in*out)
{

}

std::vector<double> wnn::Layer::process(std::vector<double> in)
{
	std::vector<double> res;
	int dim = weights.size() / wavelons.size();
	std::vector<double> wavelonInput;
	wavelonInput.resize(dim);
	for (int i = 0; i < wavelons.size(); i++)
	{
		for (int j = 0; j < dim; j++)
		{
			wavelonInput[j]=(weights[i*dim + j] * in[j]);
		}
		res.push_back(wavelons[i].process(wavelonInput));
	}
	return res;
}

std::vector<double>& wnn::Layer::getWeights()
{
	return weights;
}