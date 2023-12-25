#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <set>
#include <fstream>
#include <iomanip>

using namespace std;


const int MAXN = 26;

int mX[8] = { -1,-1,-1,0,0,1,1,1 };
int mY[8] = { -1,0,1,-1,1,-1,0,1 };

class Trie {

public:
	int prefixes;
	int words;
	vector<Trie*> child;

	Trie() : prefixes(0), words(0), child(MAXN, nullptr) {}

	~Trie() {
		for (int i = 0; i < MAXN; ++i)
			delete child[i];
	}

	void add(const char* s) {
		if (*s == '\0') ++words;
		else {
			Trie* t;
			if (child[*s - 'a'] == nullptr) {
				t = child[*s - 'a'] = new Trie();
				t->prefixes = 1;
			}
			else {
				t = child[*s - 'a'];
				t->prefixes++;
			}
			t->add(s + 1);
		}
	}

	int search(const char* s) {
		Trie* t = this;
		while (*s != '\0') {
			if (t->child[*s - 'a'] == nullptr)
				return 0;
			t = t->child[*s - 'a'];
			++s;
		}
		return t->words;
	}

	vector<int> hijos() {
		vector<int> ret;
		for (int i = 0; i < 26; i++) {
			if (child[i] != nullptr) ret.push_back(i);
		}
		return ret;
	}
};

double pulsaciones;

void cuenta(Trie* t, int pulsa, int first) {
	vector<int> hijos = t->hijos();
	
	int tmp = 0;
	if (t->words != 0) {
		tmp = 1;
		pulsaciones += pulsa;
	}

	if (hijos.size() == 0) return;
	else if(hijos.size() == 1) {
		return cuenta(t->child[hijos[0]], pulsa+tmp,0);
	}
	else {
		int sum = 0;
		for (int h : hijos) {
			cuenta(t->child[h], pulsa+1-first,0);
		}
		return;
	}
}

bool resuelveCaso() {
	double N;
	cin >> N;
	if (!cin) return false;
	pulsaciones = 0;
	Trie* trie=new Trie;
	string tmp;
	for (int i = 0; i < N; i++) {
		cin >> tmp;
		tmp += '\0';
		trie->add(tmp.c_str());
	}
	cuenta(trie, 1, 1);
	int a =(pulsaciones / N) * 1000;
	int mod = a % 10;	
	double ret = (pulsaciones / N) + ((a == 0) ? 0 : 0.001);
	
	cout << fixed << setprecision(2) << ret << "\n";

	return true;
}

int main() {
#ifndef DOMJUDGE
	std::ifstream in("datos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf()); 
#endif 

	while (resuelveCaso());
		
#ifndef DOMJUDGE 
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif

	return 0;
}
