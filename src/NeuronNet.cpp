#include "NeuronNet.h"

NeuronNet::NeuronNet(size_t _L, const vector <size_t> &nums, double(*act_func)(double)) : L(_L) {				//nums[i] -- height of layers[i]
	layers = new vector <Neuron>[L], activations = new vector <double>[L];
	activations[0].resize(nums[0]);
	for (size_t l(1); l < L; ++l) {
		activations[l].resize(nums[l]);
		layers[l].resize(nums[l]);
		for (size_t k(0); k < nums[l]; ++k)
			layers[l][k] = Neuron(nums[l - 1], act_func);
	}
}

NeuronNet::~NeuronNet() {
	delete[] layers;
	delete[] activations;
}

double NeuronNet::forward_pass(const vector <double> &input) {
	activations[0][0] = 1;
	for (size_t k(1); k <= input.size(); ++k)
		activations[0][k] = input[k - 1];

	for (size_t l(1); l < L; ++l) {
		for (size_t k(0); k < activations[l].size(); ++k)
			activations[l][k] = layers[l][k].activation(layers[l][k].summatory(activations[l - 1]));
		if (l < L - 1)
			activations[l][0] = 1;
	}
	return activations[L - 1][0];
}

void NeuronNet::backpropagation(const vector <double> &input, const bool y, const double learning_rate,
								double(*act_prime)(double), double(*target_prime)(double, double)) {
	double y_hat(forward_pass(input));
	vector <double> wdelt(1), wdelt2;
	wdelt[0] = target_prime(y_hat, y) * act_prime(layers[L - 1][0].summatory(activations[L - 2]));

	for (size_t j(0); j < layers[L - 1][0].weights.size(); ++j)
		layers[L - 1][0].weights[j] -= learning_rate * wdelt[0] * activations[L - 2][j];

	for (size_t l(L - 2); l > 0; --l) {
		wdelt2 = wdelt;
		wdelt.resize(activations[l].size());
		for (size_t k(0); k < wdelt.size(); ++k) {
			wdelt[k] = 0;
			for (size_t err(0); err < wdelt2.size(); ++err)
				wdelt[k] += wdelt2[err] * layers[l + 1][err].weights[k];
			wdelt[k] *= act_prime(layers[l][k].summatory(activations[l - 1]));

			for (size_t j(0); j < layers[l][k].weights.size(); ++j)
				layers[l][k].weights[j] -= learning_rate * wdelt[k] * activations[l - 1][j];
		}
	}
}