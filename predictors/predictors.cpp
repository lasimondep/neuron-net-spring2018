#include <ctime>
#include <sstream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

const int k(20);

vector <pair <double, double> > spec;

void recalc(const char *s, int c) {
	freopen(s, "r", stdin);
	int m, n;
	scanf("%d", &n);
	for (int i(0); i < n; ++i) {
		scanf("%d", &m);
		spec.resize(m);
		for (int j(0); j < m; ++j)
			scanf("%lf", &spec[j].first);
		for (int j(0); j < m; ++j)
			scanf("%lf", &spec[j].second);
		sort(spec.begin(), spec.end());
		for (int j(0); j < k; ++j)
			printf("%.10lf ", spec[m - j - 1].second / 8000);
		printf("%d\n", c);
	}
}

int main() {
	auto Time(time(NULL));
	auto TM(localtime(&Time));
	stringstream ss;
	ss << TM->tm_hour << TM->tm_min << TM->tm_sec;
	string filename;
	ss >> filename;
	filename = "pred" + filename + ".p";
	freopen(filename.c_str(), "w", stdout);
	int n1, n2;
	freopen("predictors/whole", "r", stdin);
	scanf("%d", &n1);
	freopen("predictors/broken", "r", stdin);
	scanf("%d", &n2);
	printf("%d %d\n", n1 + n2, k);
	recalc("predictors/whole", 1);
	recalc("predictors/broken", 0);
	return 0;
}