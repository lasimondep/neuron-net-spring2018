#include "Neuron.h"

class NeuronNet {
	size_t L;
	vector <Neuron> *layers;
	vector <double> *activations;
	public:
	NeuronNet() {}
	NeuronNet(size_t, const vector <size_t>&, double(*)(double) = sigmoid);
	~NeuronNet();
	double forward_pass(const vector <double>&);
	void backpropagation(const vector <double>&, const bool, const double, double(*)(double) = sigmoid_prime, double(*)(double, double) = quadratic_prime);
};
