#include <iostream>
#include <vector>
#include "Vertex.h"
using namespace std;
 
int main() {
        int liczba_grafow, liczba_wierzcholkow;
        int index, liczba_sasiadow;
        bool *CT;
 
        Vertex* vtx;
 
        cin >> liczba_grafow;
 
        for (int i = 0; i < liczba_grafow; i++) {
                vector<Vertex*> tablica;
                cin >> liczba_wierzcholkow;
                CT = new bool[liczba_wierzcholkow];
 
                for (int j = 0; j < liczba_wierzcholkow; j++) {
                        vtx = new Vertex();
 
                        cin >> liczba_sasiadow;
                        vtx->ilosc_sasiadow = liczba_sasiadow;
 
                        vtx->sasiedzi = new int[liczba_sasiadow];
 
                        for (int x = 0; x < liczba_sasiadow; x++) {
                                cin >> index;
                                vtx->sasiedzi[x] = index;
                        }
                        tablica.push_back(vtx);
                }
 
                tablica[0]->kolor = 0;
                int wynik = 0;
 
                for (int j = 1; j < liczba_wierzcholkow; j++) {
                        for (int a = 0; a < liczba_wierzcholkow; a++) {
                                CT[a] = false;
                        }
 
                        liczba_sasiadow = tablica[j]->ilosc_sasiadow;
                        for (int l = 0; l < liczba_sasiadow; l++) {
                                if (tablica[tablica[j]->sasiedzi[l]]->kolor != -1)
                                        CT[tablica[tablica[j]->sasiedzi[l]]->kolor] = true;
                        }
 
                        for (int l = 0; l < liczba_wierzcholkow; l++) {
                                if (CT[l] == false) {
                                        tablica[j]->kolor = l;
                                        break;
                                }
                        }
                }
 
                for (int z = 0; z < liczba_wierzcholkow; z++) {
                        if (tablica[z]->kolor >= wynik)
                                wynik = tablica[z]->kolor;
                }
 
                cout << wynik + 1 << endl;
 
        }
 
        return 0;
}