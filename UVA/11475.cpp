#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <fstream>

using namespace std;

string P;
vector<int> b; // back table
int m; // length of P

void kmpPreprocess() { // before calling kmpSearch
    m = P.size();
    b.assign(m+1, 0);
    int i = 0, j = -1; b[0] = -1;
    while (i < m) {
        while (j >= 0 && P[i] != P[j]) j = b[j];
        ++i; ++j;
        b[i] = j;
    }
}



bool resuelveCaso() {   
    string T, aux;       
    cin >> T;
    if (!cin) return false;

    aux = T;
    int i;    
    reverse(aux.begin(), aux.end());
    P = aux + "$" + T;

    kmpPreprocess();    
    i = b[P.size()];

    cout << T + aux.substr(i) << "\n";
    return true;
}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("datos.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif 


    
    while (resuelveCaso());


    // Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif

    return 0;
}