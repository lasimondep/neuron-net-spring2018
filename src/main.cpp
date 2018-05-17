#include <cstdio>
#include <ctime>
#include "body.h"

using namespace std;

NeuronNet *net;
size_t n, m;							//Nums of examples & predictors
vector <double> *input;
vector <bool> y;
const size_t epoch(75000);
const double learning_rate(0.05);

int main() {
	srand(time(NULL));

	//Получение обучающей выборки
	printf("Print learning data filename: ");
	char filename[30];
	FILE *file;
	scanf("%s", filename);
	file = fopen(filename, "r");
	reading(file, n, m, input, y);
	fclose(file);

	//Создание и обучение нейросети
	const vector <size_t> nums = {m + 1, m / 2, m / 2, 1}; //nums -- маска для слоёв нейросети
	net = new NeuronNet(4, nums);
	learning(n, input, y, *net, epoch, learning_rate);

	//Вывод активаций на обучающей выборке
	puts("Ckecking learning set:");
	printf("Mean square error: %.5lf\n", check(n, *net, input, y));

	delete[] input;

	//Получение контрольной выборки
	printf("\nPrint verification data filename: ");
	scanf("%s", filename);
	file = fopen(filename, "r");
	reading(file, n, m, input, y);
	fclose(file);

	//Вывод активаций на контрольной выборке
	puts("Checking verification set:");
	printf("Mean square error: %.5lf\n", check(n, *net, input, y));
	return 0;
}   