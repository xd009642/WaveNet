#include "layer.h"



wnn::WavelonLayer::WavelonLayer(int in, int out) :
wavelons(out, wnn::Wavelon(in)),
weights(in*out)
{
	std::generate_n(weights.begin(), weights.size(), [](){return (double)(rand()%100-50)/100.0; });
}

std::vector<double> wnn::WavelonLayer::process(std::vector<double> in)
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

std::vector<double>& wnn::WavelonLayer::getWeights()
{
	return weights;
}


wnn::OutputLayer::OutputLayer(int in) :
weights(in + 1)
{
	std::generate_n(weights.begin(), weights.size(), [](){return (double)(rand() % 100 - 50) / 100.0; });
}

std::vector<double>& wnn::OutputLayer::getWeights()
{
	return weights;
}

double wnn::OutputLayer::process(std::vector<double> in)
{
	double res = weights[0];
	for (int i = 0; i < in.size(); i++)
	{
		res += weights[i + 1] * in[i];
	}
	return res;
}