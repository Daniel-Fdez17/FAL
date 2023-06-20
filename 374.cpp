#include<iostream>
#include<vector>
using namespace std;

void resuelveCaso() {
	long long int x; cin >> x;
	long long int max = x, min = x;
	int n_max = 1, n_min = 1, i = 0;
	while (x != 0) {
		if (i != 0) {
			if (x > max) {
				max = x;
				n_max = 1;
			}
			else if (x == max) n_max++;
			if (x < min) {
				min = x;
				n_min = 1;
			}
			else if (x == min) n_min++;
		}
		i++;
		cin >> x;
	}
	cout << min << " " << n_min << " " << max << " " << n_max << "\n";
}


int main() {
	int numcasos; cin >> numcasos;
	for (int i = 0; i < numcasos; i++) resuelveCaso();
	return 0;
}