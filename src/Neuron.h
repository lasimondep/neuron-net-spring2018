#include <vector>
#include <cstdlib>
#include "func.h"

using namespace std;

class Neuron {
	private:
	size_t wsize;
	vector <double> weights;
	public:
	Neuron() {}
	Neuron(size_t, double(*)(double));
	double summatory(const vector <double>&);
	double (*activation)(double);
	friend class NeuronNet;
};
