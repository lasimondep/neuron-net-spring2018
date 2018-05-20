#include <cstdio>
#include "body.h"

void reading(FILE *file, size_t &n, size_t &m, vector <double> *&input, vector <bool> &y) {
	fscanf(file, "%u%u", &n, &m);
	input = new vector <double>[n];
	y.resize(n);
	int ans;
	for (size_t i(0); i < n; ++i) {
		input[i].resize(m);
		for (size_t j(0); j < m; ++j)
			fscanf(file, "%lf", &input[i][j]);
		fscanf(file, "%d", &ans);
		y[i] = ans;
	}
}

void learning(const size_t n, const vector <double> input[], const vector <bool> &y, NeuronNet &net, const size_t epoch, const double learning_rate) {
	for (size_t ep(0); ep < epoch; ++ep) {
		size_t c(rand() % n);
		net.backpropagation(input[c], y[c], learning_rate);
	}
}

double check(size_t n, NeuronNet &net, const vector <double> input[], const vector <bool> &y) {
	double tmp;
	int res(0);
	for (size_t i(0); i < n; ++i) {
		tmp = net.forward_pass(input[i]);
		printf("%.5lf => %s [%s]\n", tmp, tmp < 0.5 ? "broken" : "whole", y[i] ? "WHOLE" : "BROKEN");
		res += ((tmp < 0.5) && y[i]) || ((tmp >= 0.5) && !y[i]);
	}
	return res * 100.0 / n;
}