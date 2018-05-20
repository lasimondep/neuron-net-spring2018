#include "Neuron.h"

using namespace std;

Neuron::Neuron(size_t m, double(*act_func)(double)) : wsize(m), weights(m), activation(act_func) {
	for (size_t j(0); j < wsize; ++j)
		weights[j] = rand() * 1.0 / (1 << 15);
}

double Neuron::summatory(const vector <double> &la) {
	double res(0);
	for (size_t j(0); j < la.size(); ++j)
		res += la[j] * weights[j];
	return res;
}