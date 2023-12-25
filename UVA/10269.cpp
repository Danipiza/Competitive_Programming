#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <fstream>
#include <queue>
#include <climits>

using namespace std;

#define MAX 100
#define INF INT_MAX

// Explicacion rapida:
// Como Mario tiene uso en las botas creo un grafo con V*(K+1) nodos
//  cada nodo se repite k+1, con los usos de las botas, para 
//  juntar los nodos que puede visitar en 0 tiempo. Tiene en cuanta la 
//  distancia minima calculada con Floyd y la arista original. Si el camino
//  minimo es menor a la duracion de un uso de la bota se puede poner arista si
//  no pasa por un castillo, tambien tiene en cuanta el original por si el camino 
//  minimo pasa por un castillo. 
// Una vez creado el grafo se hace dijkstra para ver cuanto tarda, en llegar a
//  al primer nodo, que puede ser 0(sub0), 0(sub1), ... 0(subK)
//

using ii = pair<int, int>;
using vii = vector<ii>;
using vvii = vector<vii>;

using vi = vector<int>;
using vvi = vector<vi>;

int A, B, M, L, K;
int V;

vvii G;

vvi adjMat, camino;
void floyd() {
    camino.assign(V, vector<int>(V, INF));
    for (int k = 0; k < V; k++)
        for (int i = 0; i < V; i++)            
            for (int j = 0; j < V; j++)
                if (adjMat[i][k]!=INF && adjMat[k][j]!=INF && adjMat[i][k] + adjMat[k][j] < adjMat[i][j]) {
                    adjMat[i][j] = adjMat[i][k] + adjMat[k][j];
                    camino[i][j] = k;
                }
}

int puede(int k, int l) {
    l = camino[k][l];
    while (l != INF) {
        if (A - l <= 0) return 0;
        l = camino[k][l];
    }
    return 1;
}

int antiguo(int k, int l) {
    for (auto a : G[k]) {
        if (a.second == l) return a.first <= L;
    }
    return 0;
}

void init() {    
    int cont;
    for (int k = 0; k < V; k++) {
        for (int l = 0; l < V; l++) {            
            if (k!=l && adjMat[k][l] <= L && (puede(k, l)||antiguo(k,l))) {
                cont = V;
                for (int m = 0; m < K; m++) {
                    G[k + cont - V].push_back({ 0,l + cont });
                    cont += V;
                }
            }
        }
    }
}

vi dist;
int dijkstra(){
    dist.assign(V * (K + 1), INF);
    dist[V-1] = 0;
    priority_queue<ii, vii, greater<ii>> pq;
    pq.push({ 0, V-1 });
    while (!pq.empty()) {
        ii front = pq.top(); pq.pop();
        int d = front.first, u = front.second;
        if (d > dist[u]) continue;
        if (u % V == 0) return d;

        for (auto a : G[u]) {
            if (dist[u] + a.first < dist[a.second]) {
                dist[a.second] = dist[u] + a.first;
                pq.push({ dist[a.second], a.second });
            }
        }
    }
    return -1;
}


void resuelveCaso() {
    cin >> A >> B >> M >> L >> K;
    int a, b, d;
    V = A + B;
    G.assign(V * (K + 1), vii());
    adjMat.assign(V, vector<int>(V,INF));
    int cont;
    for (int i = 0; i < M; i++) {
        cin >> a >> b >> d;
        a--; b--;
        cont = 0;
        for (int i = 0; i <= K; i++) {
            G[a + cont].push_back({ d,b + cont });
            G[b + cont].push_back({ d,a + cont });
            cont += V;
        }    
        adjMat[a][b] = d;
        adjMat[b][a] = d;
    }
    floyd();
    if (K > 0) init();
    cout << dijkstra() << "\n";  
}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("datos.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif 

    int nCase;
    cin >> nCase;
    for (int i = 0; i < nCase; i++) { resuelveCaso(); }



    // Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif

    return 0;
}