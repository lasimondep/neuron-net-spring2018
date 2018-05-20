#include <cstdio>
#include <ctime>
#include "body.h"

using namespace std;

NeuronNet *net;
size_t n, m;							//Nums of examples & predictors
vector <double> *input;
vector <bool> y;
const size_t epoch(50000);
const double learning_rate(0.05);

int main() {
	srand(time(NULL));

	printf("Print learning data filename: ");
	char filename[30];
	FILE *file;
	scanf("%s", filename);
	file = fopen(filename, "r");
	reading(file, n, m, input, y);
	fclose(file);

	const vector <size_t> nums = {m + 1, m / 2, m / 2, 1};
	net = new NeuronNet(4, nums);
	learning(n, input, y, *net, epoch, learning_rate);

	puts("Ckecking learning set:");
	printf("Error preditions: %.2lf%%\n", check(n, *net, input, y));

	delete[] input;

	printf("\nPrint verification data filename: ");
	scanf("%s", filename);
	file = fopen(filename, "r");
	reading(file, n, m, input, y);
	fclose(file);

	puts("Checking verification set:");
	printf("Error preditions: %.2lf%%\n", check(n, *net, input, y));
	return 0;
}   