#include <iostream>
#include <iomanip>
#include <fstream>
#include <unordered_map>
#include <vector>

using namespace std;




// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int n, m;
    cin >> n >> m;
        
    if (!std::cin)
        return false;

    unordered_map<int, vector<int>> map;
    int aux;
    for (int i = 0; i < n; i++) {
        cin >> aux;
        map[aux].push_back(i + 1);
    }
    
    int k, v;
    for (int i = 0; i < m; i++) {
        cin >> k >> v;
        int ret = 0;
        if (map.find(v) != map.end()) {
            if (map[v].size() >= k) ret = map[v][k - 1];
        }
        cout << ret << "\n";
    }
    

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