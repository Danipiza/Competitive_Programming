#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <queue>
#include <climits>
#include <set>

using namespace std;

#define INF INT_MAX

using vi = vector<int>;
using vvi = vector<vi>;

struct Arista {
    int t, v;
};

struct Nodo {
    int d, t, v;
    int restante;

    bool operator<(const Nodo& otro)const {
        return otro.d < d;
    }
};

vector<vector<Arista>> adjList;
vi dist, toll;
int N, M, s, dest, p;

void dijkstra() {
    dist.assign(N, INF);
    toll.assign(N, -1);
    vector<set<int>> llegan(N,set<int>());
    dist[s] = 0; toll[s] = 0;

    priority_queue<Nodo> pq;
    pq.push({ 0, 0, s, p });

    Nodo front;
    int d, t, v, rest, tmpD = 0;
    while (!pq.empty()) {
        front = pq.top(); pq.pop(); 
        d = front.d, t = front.t, v = front.v;
        if (d > dist[v] && t < toll[v]) continue;

        for (auto a : adjList[v]) { 
            t = front.t;
            rest = front.restante - a.t;
            if (rest < 0) continue;

            tmpD = d + a.t; 
            if (t < a.t) t = a.t;

            if (tmpD < dist[a.v]) {
                if (t > toll[a.v]) {
                    toll[a.v] = t;
                    llegan[a.v].clear();
                    llegan[a.v].insert(v);
                }
                else if (t == toll[a.v] && llegan[a.v].count(v)==0) {
                    llegan[a.v].insert(v);
                }
                dist[a.v] = tmpD;
                pq.push({ tmpD, t, a.v, rest });
            }
            else if (t >= toll[a.v]) {
                if (llegan[a.v].count(v) == 0 && t == toll[a.v]) {
                    llegan[a.v].insert(v);
                    pq.push({ tmpD, t, a.v, rest });
                }
                else if(t > toll[a.v]) {
                    toll[a.v] = t;
                    llegan[a.v].clear();
                    llegan[a.v].insert(v);
                    pq.push({ tmpD, t, a.v, rest });
                }
                
            }
        }
    }
}


// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    cin >> N >> M >> s >> dest >> p;
    s--; dest--;
    int u, v, c;
    adjList.assign(N, vector<Arista>());
    for (int i = 0; i < M; i++) {
        cin >> u >> v >> c;
        u--; v--;
        adjList[u].push_back({ c,v });
    }
    dijkstra();
    cout << toll[dest] << "\n";
    
    return true;
}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("datos.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif 

    int T;
    cin >> T;
    for (int i = 0; i < T;i++) resuelveCaso();


    // Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif

    return 0;
}