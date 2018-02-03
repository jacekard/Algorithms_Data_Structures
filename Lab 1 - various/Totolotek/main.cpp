#include <iostream>
using namespace std;
//n - ilosc poprzednich losowan
//l - ilosc znalezionych losowan
void zamien(int &a, int &b) {
	int temp = a;
	a = b;
	b = temp;
}

void bubble_sort(int *t, int il_elem) {
	for (int i = 0; i < il_elem; i++) {
		for (int j = 1; j < il_elem; j++) {
			if (t[j - 1] < t[j])
				zamien(t[j - 1], t[j]);
		}
	}
}

void quick_sort(int *tab, int lewy, int prawy) {
	if (prawy <= lewy) return;
	int i = lewy - 1, j = prawy + 1,
		pivot = tab[(lewy + prawy) / 2];
	while (1) {
		while (pivot > tab[++i]);
		while (pivot < tab[--j]);
		if (i <= j) zamien(tab[i], tab[j]);
		else break;
	}
	if (j > lewy) quick_sort(tab, lewy, j);
	if (i < prawy) quick_sort(tab, i, prawy);
}
struct A {
	int licznik;
	int liczba;
} tab[1000001];
int znajdz(A *t, int l, int p, int szuk) {
	int srodek;
	while (l <= p) {
		srodek = (l + p) / 2;
		if (szuk == t[srodek].liczba) break;
		else if (szuk > t[srodek].liczba) l = srodek + 1;
		else p = srodek - 1;
	}
	return srodek;
}
int num[1000001];
int main() {
	int *t = new int[5];
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d %d %d %d %d", &t[0], &t[1], &t[2], &t[3], &t[4]);
		bubble_sort(t, 5);
		num[i] = (t[0] << 24) + (t[1] << 18) + (t[2] << 12) + (t[3] << 6) + t[4];
	}
	quick_sort(num, 0, n - 1);
	int p = 0;
	tab[p].licznik = 1;
	tab[p].liczba = num[0];
	for (int i = 1; i < n; i++) {
		if (num[i] == num[i - 1])
			tab[p].licznik++;
		else {
			tab[++p].licznik = 1;
			tab[p].liczba = num[i];
		}
	}
	p = p + 1;
	while (scanf(" %d %d %d %d %d", &t[0], &t[1], &t[2], &t[3], &t[4]) != EOF) {
		bubble_sort(t, 5);
		int numb = (t[0] << 24) + (t[1] << 18) + (t[2] << 12) + (t[3] << 6) + t[4];
		int index = znajdz(tab, 0, p, numb);
		if (tab[index].liczba == numb)
			printf("%d\n", tab[index].licznik);
		else printf("*\n");
	}
	return 0;
}