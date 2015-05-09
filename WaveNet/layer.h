#pragma once

#include "Wavelon.h"
#include <vector>
#include <algorithm>

namespace wnn
{
	template<typename T>
	class Layer
	{
	public:
		virtual ~Layer() = 0;
		virtual T process(std::vector<double> in) = 0;
		virtual std::vector<double>& getWeights() =0;
	};

	class WavelonLayer:public Layer<std::vector<double>>
	{
	public:
		WavelonLayer(int in, int out);
		virtual std::vector<double> process(std::vector<double> in) override;
		virtual std::vector<double>& getWeights() override;
	private:
		std::vector<Wavelon> wavelons;
		std::vector<double> weights;
	};

	class OutputLayer :public Layer<double>
	{
	public:
		OutputLayer(int in);
		virtual double process(std::vector<double> in) override;
		virtual std::vector<double>& getWeights() override;
	private:
		std::vector<double> weights;
	};
}