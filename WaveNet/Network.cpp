#include "network.h"


wnn::Network::Network(int in, int wavelons) :
wavelons(in, wavelons),
out(wavelons * 2)
{

}


double wnn::Network::process(std::vector<double> in)
{
	auto wout = wavelons.process(in);
	wout.insert(wout.end(), in.begin(), in.end());
	
	return out.process(wout);
}