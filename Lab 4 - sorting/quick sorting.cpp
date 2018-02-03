#include <iostream>
using namespace std;
 
 
void wypiszTablice(int *tab, int size) {
        for (int i = 0; i < size; i++) {
                cout << tab[i] << " ";
        }
        cout << endl;
}
 
int partition(int *tab, int p, int r) // dzielimy tablice na dwie czesci, w pierwszej wszystkie liczby sa mniejsze badz rowne x, w drugiej wieksze lub rowne od x
{
        int x = tab[p]; // obieramy x
        int i = p, j = r, w; // i, j - indeksy w tabeli
        while (true) // petla nieskonczona - wychodzimy z niej tylko przez return j
        {
                while (tab[j] > x) // dopoki elementy sa wieksze od x
                        j--;
                while (tab[i] < x) // dopoki elementy sa mniejsze od x
                        i++;
                if (i < j) // zamieniamy miejscami gdy i < j
                {
                        w = tab[i];
                        tab[i] = tab[j];
                        tab[j] = w;
                        i++;
                        j--;
                }
                else // gdy i >= j zwracamy j jako punkt podzialu tablicy
                        return j;
        }
}
 
void quicksort(int *tab, int p, int r)
{
        int q;
        if (p < r)
        {
 
                q = partition(tab, p, r);
 
                cout << p << "-" << q << "-" << r << " ";
                for (int l = p;  l <= r; l++) {
                        cout << tab[l] << " ";
                }
                cout << endl;
 
                quicksort(tab, p, q);
                quicksort(tab, q + 1, r); 
        }
 
        if (p == r) {
                cout << p << " " << tab[p];
                cout << endl;
        }
}
 
 
 
 
int main() {
        int *tab, rozmiar;
        while (cin >> rozmiar) {
                tab = new int[rozmiar];
                for (int i = 0; i < rozmiar; i++) {
                        cin >> tab[i];
                }
 
                quicksort(tab, 0, rozmiar - 1);
 
        }
 
        //system("pause");
        return 0;
}