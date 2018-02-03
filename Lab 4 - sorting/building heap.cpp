#include <iostream>
using namespace std;
 
void wypiszTablice(int *tab, int size) {
        for (int i = 0; i < size; i++) {
                cout << tab[i] << " ";
        }
        cout << endl;
}
 
void heapify(int *tab, int n, int size) {
        int L = n * 2;
        int R = n * 2 + 1;
        int max = 0;
        if (L <= size && tab[L - 1] > tab[n - 1])
                max = L;
        else
                max = n;
        if (R <= size && tab[R - 1] > tab[max - 1])
                max = R;
        if (max != n) {
                swap(tab[n - 1], tab[max - 1]);
                /*int tmp = tab[n - 1];
                tab[n - 1] = tab[max - 1];
                tab[max - 1] = tmp;*/
                heapify(tab, max, size);
        }
}
 
void budujKopiec(int *tab, int size) {
        for (int i = size/2; i > 0; i--) {
                heapify(tab, i, size);
                wypiszTablice(tab, size);
        }
}
 
int main() {
        int n;
        int *tab;
        while (cin >> n) {
                tab = new int[n];
                for (int i = 0; i < n; i++) {
                        cin >> tab[i];
                }
 
                budujKopiec(tab, n);
                
        }
 
        //system("pause");
        return 0;
}