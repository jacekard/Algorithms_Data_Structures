#include <iostream>
#include <stack>
#include <string>
using namespace std;
 
int main() {
        int numb;
        cin >> numb;
        stack <string> wynik;
        string instr;
 
        for (int j = 0; j < numb; j++) {
                cin >> instr;
                int rozmiar = instr.size();
                for (int i = rozmiar - 1; i >= 0; i--) {
 
                        string a = string(1, instr[i]);
 
                        if (a == "t" || a == "f")
                                wynik.push(a);
                        else if (a == "K" || a == "A") {
                                string wyr1 = wynik.top();
                                wynik.pop();
                                string wyr2 = wynik.top();
                                wynik.pop();
                                wynik.push("(" + wyr1 + a + wyr2 + ")");
                        }
                        else if (a == "N") {
                                string wyr1 = wynik.top();
                                wynik.pop();
                                wynik.push("(N" + wyr1 + ")");
                        }
                }
                cout << wynik.top() << endl;
        }
 
        return 0;
}
 