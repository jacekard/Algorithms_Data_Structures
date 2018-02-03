#include <iostream>
#include <vector>
#include <stack>
#include "Vertex.h"
using namespace std;
 
int main() {
        int liczba_grafow, liczba_wierzcholkow;
        int index, liczba_sasiadow;
        int *C;
 
 
        cin >> liczba_grafow;
 
        for (int i = 0; i < liczba_grafow; i++) {
 
        vector<Vertex*> tablica;
        Vertex* vtx;
        stack<int> stos;
                cin >> liczba_wierzcholkow;
                C = new int[liczba_wierzcholkow];
 
                for (int i = 0; i < liczba_wierzcholkow; i++) {
                        C[i] = 0;
                }
 
                for (int j = 0; j < liczba_wierzcholkow; j++) {
                        vtx = new Vertex();
                        vtx->index = j;
                        cin >> liczba_sasiadow;
                        vtx->ilosc_sasiadow = liczba_sasiadow;
                        vtx->sasiedzi = new int[liczba_sasiadow];
                        for (int x = 0; x < liczba_sasiadow; x++) {
                                cin >> index;
                                vtx->sasiedzi[x] = index;
                        }
                        tablica.push_back(vtx);
                }
 
                int sklad_spoj = 0;
 
                for (int r = 0; r < liczba_wierzcholkow; r++) {
                        if (C[r] > 0) continue;
                        sklad_spoj++;
                        stos.push(r);
                        C[r] = sklad_spoj;
                        while (!stos.empty()) {
                                int v = stos.top();
                                stos.pop();
 
                                for (int z = 0; z < tablica[v]->ilosc_sasiadow; z++) {
                                        int u = tablica[v]->sasiedzi[z];
                                        if (C[u]) continue;
                                        stos.push(u);
                                        C[u] = sklad_spoj;
 
                                }
                        }
                }
                cout << sklad_spoj << endl;
        }
 
        return 0;
}