#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <fstream>
#include <queue>
#include <climits>

using namespace std;

using vi = vector<int>;
using vvi = vector<vi>;

#define INF INT_MAX

vvi M;
string S;

int ret;

void boton(int x, int y) {
    M[x][y] = !M[x][y];
    if (x - 1 >= 0)    M[x - 1][y] = !M[x - 1][y];
    if (x + 1 < 10)    M[x + 1][y] = !M[x + 1][y];
    if (y - 1 >= 0)    M[x][y - 1] = !M[x][y - 1];
    if (y + 1 < 10)    M[x][y + 1] = !M[x][y + 1];
}

int init() {
    string tmp;
    cin >> S;
    if (S == "end") return 0;
    M.assign(10, vi(10, 0));
    
    for (int i = 0; i < 10; i++) {
        cin >> tmp;
        for (int j = 0; j < 10; j++) {
            if (tmp[j] == 'O') M[i][j] = 1;
        }
    }
    if (S == "all_off") ret = 0;
    return 1;
}



void dfs(int x, int y, int step) {
    if (y == 10)  x++, y = 0;
    if (step >= ret) return;
    
    if (x < 10) {
        // Se pulsa por que esta activo el de arriba
        if (M[x - 1][y] == 1) {
            boton(x, y);
            dfs(x, y + 1, step + 1);
            boton(x, y);
        }
        else dfs(x, y + 1, step);
    }
    else {
        int i;
        for (i = 0; i < 10; i++) {
            if (M[x - 1][i]) return;
        }
        if (step < ret)  ret = step;
    }
}

void vueltaAtras(int j, int pulsa) {
    if (j != 10) {
        vueltaAtras(j + 1, pulsa);
        boton(0, j);
        vueltaAtras(j + 1, pulsa + 1);
        boton(0, j);
    }
    dfs(1, 0, pulsa);
}


bool resuelveCaso() {  
    ret = INF;
    if (!init()) return false;    
    if (ret != 0) vueltaAtras(0, 0);
    cout << S << " " << ret<< "\n";
    

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