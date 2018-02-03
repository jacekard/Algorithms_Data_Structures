#include<iostream>
#include <cmath>
using namespace std;

class Result {
public:
	long long nwd;
	long long p;
	long long q;
	Result() {};
	Result(long long asd1, long long asd2, long long asd3)
		: nwd(asd1), p(asd2), q(asd3) { };
};

Result NWD(long long x, long long y) {
	if (y == 0) return Result(x, 1, 0);
	else {
		Result tmp = NWD(y, x%y);
		Result wynik = Result(tmp.nwd, tmp.q, tmp.p - (x / y) * tmp.q);
		return wynik;
	}
}

int main()
{
	while (1) {
		long long a, b;
		if (scanf(" %lld\t%lld", &a, &b) == EOF) break;
		Result wynik;
		wynik = NWD(a, b);
		cout << wynik.nwd << "=" << a << "*";
		if (wynik.p < 0) cout << "(" << wynik.p << ")";
		else cout << wynik.p;
		cout << "+" << b << "*";
		if (wynik.q < 0)cout << "(" << wynik.q << ")";
		else cout << wynik.q;
		cout << endl;
	}
	return 0;
}