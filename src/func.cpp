#include <cmath>
#include "func.h"

double sigmoid(double x) {
	return 1.0 / (1 + exp(-x));
}

double sigmoid_prime(double x) {
	return x * (1 - x);
}

double target(double y, double y_hat) {
	return (y - y_hat) * (y - y_hat) / 2;
}

double target_prime(double y_hat, double y) {
	return (y_hat - y);
}