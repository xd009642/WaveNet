#include "BackPropTrainer.h"



void wnn::BackPropTrainer::train(Network& network, std::vector<double> data, double label)
{
	double actual=network.process(data);
	double error = 0.5* pow(actual - label, 2);
}