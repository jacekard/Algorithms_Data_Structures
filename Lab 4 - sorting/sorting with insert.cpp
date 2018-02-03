#include <iostream>
 
using namespace std;
 
void sortowanie_przez_wstawianie(int *tablica, int size) {
        for (int l = 1; l < size; l++) {
 
                int j = l - 1;
                
                int x = tablica[l];
                
                for (j = l - 1; j >= 0; j--) {
                        if (tablica[j] <= x) 
                                break;
                        
                        tablica[j + 1] = tablica[j];
                }
 
                tablica[j + 1] = x;
                for (int t = 0; t < size; t++) {
                      cout << tablica[t] << " ";        
 
                }
                cout << endl;
        }
}
 
int main() {
        int rozmiar, *tablica;
        
        while (cin >> rozmiar) {
                tablica = new int[rozmiar];
                for (int j = 0; j < rozmiar; j++) {
                        cin >> tablica[j];
                }
 
                sortowanie_przez_wstawianie(tablica, rozmiar);
                
        }
 
        //system("pause");
        return 0;
}