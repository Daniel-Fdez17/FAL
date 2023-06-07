#include<iostream>
#include<fstream>
#include<vector>
using namespace std;

/*
ESPECIFICACION: fun resolver(vector<int>const&v, int size, int d) ret bool

PRECONDICION: {
    0 <= d <= 1.000.000
    &&
    1 <= size <= 200.00
    &&
    forall l : 0 <= l < size : v[l] > 0 && v[l] <= 1.000.000
}

POSTCONDICION: {
    crecientes = (p,q : 0 <= p <= q < size - 1 : forall u : p <= u < q : v[u] < v[u + 1] : q - p)
    &&
    apta = exists w : 0 <= w < size - 1 : v[w] >= v[w + 1] && v[w] - v[w - crecientes] > d
}

INVARIANTE: {
    0 <= i < size
    &&
    crecientes = (p,q : 0 <= p <= q < i : forall u1 : p <= u1 < q : v[u1] < v[u1 + 1] : q - p)
    &&
    apta = exists w1 : 0 <= w1 < i : v[w1] >= v[w1 + 1] && v[w1] - v[w1 - crecientes] > d
}

FUNCION DE COTA: size - i
ANALISIS DEL COSTE: El coste de cada iteracion del bucle es constante, y este se recorre en el caso peor size - 1 veces (=== size).
    Por tanto, el coste del algoritmo pertenece a O(1) * size = O(size)
*/

bool resolver(vector<int>const& v, int size, int d) {
    bool apta = true;
    int i = 0, crecientes = 0;
    while (i < size - 1 && apta) {
        if (v[i] < v[i + 1]) {
            crecientes++;
        }
        else {
            apta = (v[i] - v[i - crecientes] <= d);
            crecientes = 0;
        }
        i++;
    }
    if (crecientes != 0)
        apta = v[size - 1] - v[size - 1 - crecientes] <= d;
    return apta;
}

bool resuelveCaso() {
    int size, d;
    cin >> d >> size;
    if (!cin) return false;
    vector<int> v(size);
    for (int& i : v)cin >> i;
    cout << (resolver(v, size, d) ? "" : "NO ") << "APTA\n";
    return true;
}


int main() {

    // ajuste para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
    std::ifstream in("in.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

    while (resuelveCaso());

    // restablecimiento de cin
#ifndef DOMJUDGE
    std::cin.rdbuf(cinbuf);
    system("pause");
#endif
    return 0;
}