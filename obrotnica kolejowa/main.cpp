#include "stos.h"
#define MAX 10
 
//t = liczba torow
//n = liczba instrukcji
//l = liczba wagonow
//zn = numer instrukcji
//x = indeks obrotnicy
//liczba
int main() {
        int t, n, l, x = 0, liczba;
        char zn = 'a';
        scanf("%d", &t);
        stos **tory = (stos **)malloc(t*sizeof(stos*));
        for (int i = 0; i < t; i++) {
                tory[i] = (stos*)malloc(sizeof(stos));
                tory[i] = NULL;
        }
        stos *obrotnica = NULL;
 
        for (int i = 0; i < t; i++) {
                scanf("%d", &l);
                int *pom = new int[l];
 
                if (l) {
                        for (int j = 0; j < l; j++) {
                                scanf("%d", &pom[j]);
                        }
                        for (int j = l - 1; j >= 0; j--) {
                                push(tory[i], pom[j]);
                        }
                }
                delete[] pom;
        }
 
        int ile_operacji = 0;
        scanf("%d", &n);
        while (1) {
                cin >> zn >> liczba;
                switch (zn) {
                case 'z': x = (x + liczba) % t;
                        break;
                case 'o':
                        x = (x - liczba) % t;
                        if (x < 0) x += t;
                        break;
                case 'w': {
                                          for (int i = 0; i < liczba; i++) {
                                                  int biez = current(tory[x]);
                                                  if (biez && rozmiar(obrotnica) < 10) {
                                                          push(obrotnica, biez);
                                                          pop(tory[x]);
                                                  }
                                          }
                } break;
                case 'j': {
                                          for (int i = 0; i < liczba; i++) {
                                                  int biez = current(obrotnica);
                                                  if (biez) {
                                                          push(tory[x], biez);
                                                          pop(obrotnica);
                                                  }
                                          }
                } break;
                default: break;
                }
                        ile_operacji++;
                        if (ile_operacji == n) break;
        }
 
        printf("\n%d ", rozmiar(obrotnica));
        wypisz(obrotnica);
        putchar('\n');
        for (int i = 0; i < t; i++) {
                printf("%d ", rozmiar(tory[(x + i) % t]));
                wypisz(tory[(x + i) % t]);
                putchar('\n');
        }
        for (int i = 0; i < t; i++) {
                free(tory[i]);
        }
        free(tory);
        return 0;
}