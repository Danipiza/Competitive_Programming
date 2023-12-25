#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <queue>
#include <climits>
#include <unordered_set>
#include <map>

using namespace std;

#define INF INT_MAX

using vi = vector<int>;
using vvi = vector<vi>;

struct Nodo {
    int d, v;

    bool operator<(const Nodo& otro)const {
        return otro.d < d;
    }
};

int N, M, Q, P;
vector<vector<Nodo>> adjList;
int cont = 0;
vvi dist;
unordered_set<int> pColes;
vi pColesIdx;
vvi caminos;

void dijkstra(int s) {
    dist[cont][s] = 0;

    priority_queue<Nodo> pq;
    pq.push({ 0, s });

    Nodo front;
    int d, v, tmpD = 0;
    while (!pq.empty()) {
        front = pq.top(); pq.pop();
        d = front.d, v = front.v;
        if (d > dist[cont][v]) continue;

        for (auto a : adjList[v]) {
            tmpD = d + a.d;

            if (tmpD < dist[cont][a.v]) {
                dist[cont][a.v] = tmpD;
                pq.push({ tmpD, a.v });
            }
        }
    }
}

int minimo;
void aux(int act, int fin, int n, int d, vi usados) {
    if (d > minimo) return;
    if (n == P) {
        d += dist[act][fin];
        if (d < minimo) minimo = d;
        return;
    }

    for (int i = 0; i < P; i++) {
        if (usados[i]) continue;
        usados[i] = 1;
        aux(i, fin, n+1, d+dist[act][pColesIdx[i]], usados);
        usados[i] = 0;
    }
}

void caminosInit() {    
    caminos.assign(P, vi(P, 0));
    for (int i = 0; i < P; i++) {
        for (int j = i + 1; j < P; j++) {
            minimo = INF;
            vi usados(P);
            usados[i] = usados[j] = 1;
            aux(i, pColesIdx[j], 2, 0, usados);
            caminos[i][j] = minimo;
            caminos[j][i] = minimo;
        }
    }
}

void pueblo(int& id, int& distancia) {
    caminosInit();
    
    int tmp;
    for (int k = 1; k <= N; k++) {
        if (pColes.count(k) > 0) continue; // pueblo

        for (int i = 0; i < P; i++) {
            for (int j = i+1; j < P; j++) {                
                tmp = caminos[i][j] + dist[i][k] + dist[j][k];
                if (tmp < distancia) {
                    distancia = tmp;
                    id = k;
                }
            }
        }
    }
}

void puebloUnitario(int& id, int& distancia) {
    int tmp;
    for (int k = 1; k <= N; k++) {
        if (pColes.count(k) > 0) continue;
        tmp = dist[0][k] * 2;
        if (tmp < distancia) {
            distancia = tmp;
            id = k;
        }
    }
}

bool resuelveCaso() {
    cin >> N >> M;
    if (!cin) return false;
    adjList.assign(N+1, vector<Nodo>());
    
    int a, b, d;
    for (int i = 0; i < M; i++) {
        cin >> a >> b >> d;
        adjList[a].push_back({ d,b });
        adjList[b].push_back({ d,a });
    }
    cin >> Q;
    for (int i = 0; i < Q; i++) {
        cin >> P;
        pColes.clear();
        pColesIdx.clear();
        cont = 0;
        dist.assign(P, vi(N + 1, INF));
        for (int j = 0; j < P; j++) {
            cin >> a;
            pColes.insert(a);
            pColesIdx.push_back(a);
            dijkstra(a);
            cont++;
        }
        int id, distancia = INF;
        if (P != 1) pueblo(id, distancia);
        else puebloUnitario(id, distancia);
        cout << id << " " << distancia << "\n";
    }
    cout << "---\n";

    return true;
}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("datos.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif 

    
    while(resuelveCaso());


    // Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif

    return 0;
}