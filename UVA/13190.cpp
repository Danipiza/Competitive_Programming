#include <iostream>
#include <iomanip>
#include <fstream>
#include <map>
#include <string>
#include <vector>
#include <queue>

using namespace std;

struct Nodo {
    int time;
    string name;
    int priority;
    bool operator<(Nodo const& otro) const {
        return otro.time < time || otro.time == time && otro.priority < priority;
    }
};



// función que resuelve el problema
void resolver(priority_queue<Nodo> Q, int n, int k, int minimo) {
    int cont = 0;
    while (cont < k) {                   
        cout << Q.top().time << " " << Q.top().name << "\n";
        Q.pop();            
            
        cont++;
    }

}



// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    int n, k;
    cin >> n >> k;
    int tmpI;
    string tmpS;
    int minimo = 10001;
    priority_queue<Nodo> Q;
    for (int i = 0; i < n; i++) {
        cin >> tmpS >> tmpI;
        for (int j = 1; j <= k; j++) {
            Nodo x;
            x.time = tmpI * j;
            x.name = tmpS;
            x.priority = i;
            Q.push(x);          
           
        }
    }
    resolver(Q,n,k,minimo);
}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("datos.in");
    auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif 


    int numCasos;
    std::cin >> numCasos;
    for (int i = 0; i < numCasos; ++i)
        resuelveCaso();


    // Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif

    return 0;
}