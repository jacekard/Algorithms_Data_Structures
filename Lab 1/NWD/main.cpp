#include <iostream>
using namespace std;

int nwd(int a, int b) {
	while (b != 0) {
		int pom = b;
		b = a%b;
		a = pom;
	}
	return a;
}

int main() {
	int a, b;
	cin >> a >> b;
	cout << nwd(a, b);
	return 0;
}
