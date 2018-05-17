#include "Neuron.h"

class NeuronNet {
	size_t L;
	vector <Neuron> *layers;
	vector <double> *activations;
	public:
	NeuronNet() {}
	NeuronNet(size_t, const vector <size_t> &);
	~NeuronNet();
	double forward_pass(const vector <double> &);
	void backpropagation(const vector <double> &, const bool, const double);
};
