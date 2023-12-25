#include <fstream>
#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <iomanip>
#include <cmath>
#include <random>
#include <tuple>
#include <cassert>
#include <algorithm>
using namespace std;

const double EPS = 1e-9;
const double PI = acos(-1);

using T = double;
//bool lt(double a, double b) { return a - EPS < b; };
//bool eq(double a, double b) { return fabs(a - b) < EPS; }

//using T = int;
//bool lt(int a, int b) { return a < b; }
//bool eq(int a, int b) { return a == b; }

struct pt {
    T x, y;

    pt(T v, T c) : x(v), y(c) {}

    pt operator+(pt p) const { return { x + p.x, y + p.y }; }
    pt operator-(pt p) const { return { x - p.x, y - p.y }; }
    pt operator*(T d) const { return { x * d, y * d }; }
    pt operator/(T d) const { return { x / d, y / d }; } // only for floating-point

    bool operator==(pt o) const { return x == o.x && y == o.y; }
    bool operator!=(pt o) const { return !(*this == o); }

    bool operator<(pt o) const { // sort points lexicographically
        if (x == o.x) return y < o.y;
        return x < o.x;
    }
};


T sq(pt v) { return v.x * v.x + v.y * v.y; }
double abs(pt v) { return sqrt(sq(v)); }

ostream& operator<<(ostream& os, pt p) {
    return os << "(" << p.x << "," << p.y << ")";
}

double dist(pt a, pt b) { // Euclidean distance
    return hypot(a.x - b.x, a.y - b.y);
}
T dist2(pt a, pt b) {
    return (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y);
}

// PRODUCTOS

T dot(pt v, pt w) { return v.x * w.x + v.y * w.y; }

bool isPerp(pt v, pt w) { return dot(v, w) == 0; }

double angle(pt v, pt w) {
    double cosTheta = dot(v, w) / abs(v) / abs(w);
    return acos(max(-1.0, min(1.0, cosTheta)));
}

T cross(pt v, pt w) { return v.x * w.y - v.y * w.x; }




// LINEAS

struct line {
    pt v; T c;
    // from direction vector v and offset c
    line(pt v, T c) : v(v), c(c) {}
    // from equation ax + by = c
    line(T a, T b, T c) : v({ b,-a }), c(c) {}
    // from points p and q
    line(pt p, pt q) : v(q - p), c(cross(v, p)) {}

    T side(pt p) { return cross(v, p) - c; }

    double dist(pt p) { return abs(side(p)) / abs(v); }

    line translate(pt t) { return { v, c + cross(v,t) }; }

};

bool inter(line l1, line l2, pt& out) {
    T d = cross(l1.v, l2.v);
    if (d == 0) return false;
    out = (l2.v * l1.c - l1.v * l2.c) / d; // requires floating-point coordinates
    return true;
}




int N;
vector<double> coef;
vector<pair<pt, pt>> vP;
vector<line> vL;
vector<double> vX;

double func(double a) {
    double ret = 1;
    
 
    for (int i = 0; i < N; i++) {          
        if (a >= vP[i].first.x && a <= vP[i].second.x) {
            ret *= coef[i];
        }
    }
    return ret;
}

void resuelveCaso() {
    // leer los datos de la entrada
    cin >> N;
    coef.assign(N,0);
    vP.clear();
    vL.clear();
    vX.clear();
    double a, b, c, d;
    for (int i = 0; i < N; i++) {
        cin >> a >> b >> c >> d >> coef[i];
        pt p1(a, b), p2(c,d);
        line l(p1, p2);
        vL.push_back(l);
        if(a<c) vP.push_back({ p1,p2 });
        else vP.push_back({ p2,p1 });
        vX.push_back(a); vX.push_back(c);
    }
    sort(vX.begin(), vX.end());

    if (N == 0) cout << "1\n-inf +inf 1.000\n";
    else {
        double tmp = vX[0];
        cout << (N * 2) + 1 << "\n";
        cout << fixed << setprecision(3) << "-inf " << vX[0] << " 1.000\n";
        for (int i = 1; i < vX.size(); i++) {
            cout << fixed << setprecision(3) << tmp << " " << vX[i] << " " << func((tmp + vX[i]) / 2) << "\n";
            tmp = vX[i];
        }
        cout << fixed << setprecision(3) << vX[vX.size()-1] << " +inf 1.000\n";
    }
    cout << "\n";
   

    
    // escribir sol


}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("datos.txt");
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
