#include<iostream>
#include<fstream>
#include<vector>
using namespace std;


/*
* A) todosPares(v,p,q) = forall j : p <= j <= q : v[j] % 2 == 0
* B) noMas(v,p,q,k) = todosPares(v,p,q) <=> q - p <= k
* 
* ESPECIFICACION: fun resolver(vector<int>const&v, int size, int k) ret int
*
* PRECONDICION: {
* size >= 0
* &&
* forall u : 0 <= u < size : v[u] > 0
* &&
* k >= 0
* }
*
* POSTCONDICION: {
* pares = p,q : 0 <= p <= q < size : todosPares(v,p,q) : q - p
* &&
* inicio = max w : 0 <= w < size : (max p,q : 0 <= p <= q < size : noMas(v,p,q,k) : q - p + 1) : w
* }
*
* INVARIANTE: {
* 0 <= i <= size
* &&
* pares = p,q : 0 <= p <= q < i : todosPares(v,p,q) : q - p
* &&
* inicio = max w1 : 0 <= w1 < i : (max p,q : 0 <= p <= q < i : noMas(v,p,q,k) : q - p + 1) : w1
* }
*
* FUNCION DE COTA: size - i
* ANALISIS DEL COSTE: El coste de cada iteracion del bucle es constante, y este se recorre size veces.
*   Por tanto, el coste del algoritmo pertenece a O(1) * size = O(size)
*/

int resolver(vector<int>const& v, int size, int k) {
    // Si el numero maximo de elementos pares consecutivos es mayor o igual a la longitud del vector, se devuelve la longitud del vector
    if (k >= size) return size;
    int pares = 0, inicio = 0;
    for (int i = 0; i < size; i++) {
        if (v[i] % 2 == 0) {
            pares++;
            if (pares > k)
                inicio = i - k + 1;
        }
        else
            pares = 0;
    }
    return size - inicio;
}


bool resuelveCaso() {
    int size, k; cin >> size >> k;
    vector<int> v(size);
    for (int& i : v)cin >> i;
    cout << resolver(v, size, k) << "\n";
    return true;
}



int main() {

    // ajuste para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
    std::ifstream in("in.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

    unsigned int numCasos;
    std::cin >> numCasos;
    // Resolvemos
    for (int i = 0; i < numCasos; ++i) {
        resuelveCaso();
    }
#ifndef DOMJUDGE
    std::cin.rdbuf(cinbuf);
    system("pause");
#endif
    return 0;
}