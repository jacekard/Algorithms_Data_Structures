#include <iostream>
#include <stack>
#include <queue>
#include <string>
 
using namespace std;
 
int main() {
 
        queue<char> output;
        stack<char> stosONP;
        string instrukcja;
        int liczbaInstr;
 
        cin >> liczbaInstr;
 
        for (int i = 0; i < liczbaInstr; i++) {
 
                cin >> instrukcja;
 
                int size = instrukcja.size();
                for (int j = 0; j < size; j++) {
 
                        char a = instrukcja[j];
 
                        if (a == 't' || a == 'f') {
                                output.push(a);
                        }
                        else if (a == '(')
                                stosONP.push(a);
                        else if (a == ')') {
                                while (stosONP.top() != '(') {
                                        output.push(stosONP.top());
                                        stosONP.pop();
                                }
                                stosONP.pop();
                        }
                        else if (a == 'K' || a == 'A' || a == 'N') {
                                while (stosONP.top() != '(') {
                                        output.push(stosONP.top());
                                        stosONP.pop();
                                }
                                stosONP.push(a);
                        }
                }
                int sizeO = output.size();
                for (int x = 0; x < sizeO; x++) {
                        char zn = output.front();
                        output.pop();
 
                        if (zn == 't' || zn == 'f') {
                                stosONP.push(zn);
                        }
                        else if (zn == 'N') {
                                //NEGACJA
                                char w1 = stosONP.top();
                                stosONP.pop();
 
                                if (w1 == 't')
                                        stosONP.push('f');
                                else
                                        stosONP.push('t');
                        }
                        else if (zn == 'K') {
                                //KONIUNKCJA
                                char w1 = stosONP.top();
                                stosONP.pop();
                                char w2 = stosONP.top();
                                stosONP.pop();
 
                                if (w1 == 't' && w2 == 't')
                                        stosONP.push('t');
                                else
                                        stosONP.push('f');
                        }
                        else if (zn == 'A') {
                                //ALTERNATYWA
                                char w1 = stosONP.top();
                                stosONP.pop();
                                char w2 = stosONP.top();
                                stosONP.pop();
 
                                if (w1 == 'f' && w2 == 'f')
                                        stosONP.push('f');
                                else
                                        stosONP.push('t');
                        }
                }
 
                cout << stosONP.top() << endl;
                stosONP.pop();
        }
 
 
        return 0;
}