#include <cmath>
#include "func.h"

double sigmoid(double x) {
	return 1.0 / (1 + exp(-x));
}

double sigmoid_prime(double x) {
	return sigmoid(x) * (1 - sigmoid(x));
}

double quadratic_prime(double y_hat, double y) {
	return (y_hat - y);
}