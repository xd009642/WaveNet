#include "BackPropTrainer.h"



void wnn::BackPropTrainer::train(Network& network, std::vector<double> data, double label)
{
	double n = 0.2, m = 0.4;
	double actual=network.process(data);
	double error = 0.5* pow(label - actual, 2);

}