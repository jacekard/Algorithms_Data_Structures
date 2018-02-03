#include <iostream>
using namespace std;

int dl(char *a) {
	int dl = 0;
	while (*(a + dl) != '\0') dl++;
	return dl;
}

int poz(char *a, char *b) {
	char *p = b;
	int l = dl(a);
	int f = dl(b);
	for (int i = 0; i < l; i++) {
		if (a[i] == *b) {
			b++;
			if (*b == '\0') return i + 1 - f;
		}
		else b = p;
	}
	return 0;
}

int main() {
	char *a = new char[100000000];
	char *b = new char[100000000];
	scanf("%s", b);
	scanf("%s", a);


	char *p = b;
	int l = dl(a);
	int f = dl(b);
	int w = 0;
	for (int i = 0; i < l; i++) {
		if (a[i] == *b) {
			b++;
			if (*b == '\0') { w = i + 1 - f; break; }
		}
		else b = p;
	}

	cout << w;
	return 0;
}