#include <iostream>
using namespace std;
 
void wypiszTablice(int *tab, int size) {
        for (int i = 0; i < size; i++) {
                cout << tab[i] << " ";
        }
        cout << endl;
}
 
void sortowanie_przez_zamiane(int *tablica, int size)  {
        bool hasChanged;
        for (int k = 0; k < size; k++) {
                hasChanged = false;
                for (int i = 0; i < size - k - 1; i++) {
                        if (tablica[i] > tablica[i + 1]) {
                                swap(tablica[i + 1], tablica[i]);
                                hasChanged = true;
                        }
                }
                if (hasChanged) {
                        wypiszTablice(tablica, size);
                }
        }
        cout << endl;
}
 
int main() {
        int *tab, rozmiar;
        while (cin >> rozmiar) {
                tab = new int[rozmiar];
                for (int i = 0; i < rozmiar; i++) {
                        cin >> tab[i];
                }
 
                sortowanie_przez_zamiane(tab, rozmiar);
                
        }
 
        //system("pause");
        return 0;
}