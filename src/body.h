#include <vector>
#include "NeuronNet.h"

using namespace std;

void reading(FILE*, size_t&, size_t&, vector <double>*&, vector <bool>&);
void learning(const size_t, const vector <double>[], const vector <bool>&, NeuronNet&, const size_t, const double);
double check(size_t, NeuronNet&, const vector <double>[], const vector <bool>&);