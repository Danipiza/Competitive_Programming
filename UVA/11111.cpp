// Nombre del alumno Daniel Pizarro
// Usuario del Juez PC04


#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <stack>

using namespace std;

// función que resuelve el problema
bool resolver(string s) {
    stringstream ss(s);
    int k;
    stack<int> pila;
    stack<int> recogidos;
    int aux = 0;
    while (ss >> k) {
        if (!pila.empty() && k == abs(pila.top())) {
            pila.pop();
            while (!recogidos.empty() && recogidos.top() < k - aux) {
                aux += recogidos.top(); recogidos.pop();
            }
            aux = 0;
            recogidos.push(k);
        }
        else if (k < 0) pila.push(k);
        else return false;
    }
    return pila.empty() && recogidos.size() == 1;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    string s;
    getline(cin, s);

    if (!std::cin)
        return false;

    if (resolver(s)) cout << ":-) Matrioshka!\n";
    else cout << ":-( Try again.\n";


    return true;

}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("datos.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif 


    while (resuelveCaso())
        ;


    // Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif

    return 0;
}