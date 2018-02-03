#include <iostream>
#include <string>

using namespace std;

int dlug(char *t) {
	int dl = 0;
	while (*(t + dl) != NULL) dl++;
	return dl;
}

int maksimum(int a, int b) {
	if (a > b) return a;
	else return b;
}

int main()
{
	char *a = new char[10000000];
	char *b = new char[10000000];
	string podcg;
	int ** POM;
	int x, y;

	scanf("%s %s", a, b);

	x = dlug(a);
	y = dlug(b);

	POM = new int *[x + 1];
	int z = 0;
	while (z <= x) {
		POM[z] = new int[y + 1];
		z++;
	}
	while (z <= x) {
		POM[z][0] = 0;
		z++;
	}
	while (z <= x) {
		POM[0][z] = 0;
		z++;
	}

	int k, l;
	for (k = 0; k < x; k++) {
		for (l = 0; l < y; l++) {
			if (a[k] == b[l]) {
				POM[k + 1][l + 1] = 1 + POM[k][l];
			}
			else {
				if (POM[k + 1][l] > POM[k][l + 1]) {
					POM[k + 1][l + 1] = POM[k + 1][l];
				}
				else {
					POM[k + 1][l + 1] = POM[k][l + 1];
				}
			}
		}
	}

	podcg = "";
	k = x - 1;
	l = y - 1;
	while ((k >= 0) && (l >= 0)) {
		if (a[k] == b[l]) {
			podcg = a[k] + podcg;
			k--; l--;
		}
		else if (POM[k + 1][l] > POM[k][l + 1])
			l--;
		else k--;
	}

	cout << podcg;
	return 0;
}