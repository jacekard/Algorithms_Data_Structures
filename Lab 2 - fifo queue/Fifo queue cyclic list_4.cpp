#include <stdio.h>
#include <iostream>
using namespace std;
 
enum {
        CMD_LENGTH,
        CMD_PRINT,
        CMD_ERROR,
        CMD_EMPTY,
        CMD_ADD,
        CMD_WYJMIJ,
        CMD_USUN,
} ecmd;
 
struct Elem {
        int key;
        Elem* next;
        bool del;
        Elem(Elem* e, int k) : next(e), key(k), del(false) { }
};
 
char cmd;
int n, k;
bool isEmptyQueue;
Elem *first, *last;
 
 
int parseEnum(char cmd) {
        return cmd == 'L' ? CMD_LENGTH :
                cmd == 'P' ? CMD_PRINT :
                cmd == 'C' ? CMD_EMPTY :
                cmd == 'E' ? CMD_ADD :
                cmd == 'D' ? CMD_WYJMIJ :
                cmd == 'R' ? CMD_USUN :
                CMD_ERROR;
}
 
Elem *search(int key)
{
        if (!first) return NULL;
        Elem *tmp = first;
        while (tmp->key != key && tmp != last) tmp = tmp->next;
        if (tmp->key == key) return tmp;
        else return NULL;
}
 
void printAll() {
        if (!first || isEmptyQueue) printf("-\n");
        else {
                Elem *tmp = first;
                while (tmp != last) {
                        if (tmp->del == false)
                                printf("%d->", tmp->key);
                        tmp = tmp->next;
                }
                printf("%d\n", last->key);
        }
}
 
int totalLength()
{
        if (!first) return 0;
        int len(1);
        Elem *tmp = first;
        while (tmp->next != first) {
                tmp = tmp->next;
                len++;
        }
        return len;
}
 
void add_empty() {
        Elem *t = new Elem(NULL, NULL);
        if (!first) {
                first = t;
                last = t;
                t->next = first;
        }
        else {
                t->next = last->next;
                last->next = t;
        }
}
 
void add_new(int klucz) {
        //pusta
        if (!first) {
                add_empty();
        }
        //pierwszy element
        if (isEmptyQueue) {
                isEmptyQueue = false;
                first->key = klucz;
        }
        else {
                if (last->next == first) add_empty();
                last = last->next;
                last->key = klucz;
        }
}
 
void wyjmij() {
        if (!isEmptyQueue) {
                cout << first->key << " ";
                if (first == last)
                        isEmptyQueue = true;
                else
                        first = first->next;
        }
        else
                cout << "- ";
 
}
 
void usun(int k) {
        if (!isEmptyQueue) {
                Elem *tmp = search(k);
                Elem *poprz = tmp;
                if (tmp != NULL) {
                        while (poprz->next != tmp) {
                                poprz = poprz->next;
                        }
                        poprz->next = tmp->next;
 
                        if (tmp == first && first == last) {
                                isEmptyQueue = true;
                                first = NULL;
                                last = NULL;
                                return;
                        }
                        else if (tmp == first) {
                                first = first->next;
                        }
                        else if (tmp == last) {
                                last = poprz;
                        }
                        delete tmp;
                }
                else printf("-\n");
        }
        else printf("-\n");
}
char zn;
int main() {
        isEmptyQueue = true;
        while (scanf("%c", &cmd) > 0) {
                switch (parseEnum(cmd))
                {
                case CMD_LENGTH:
                        printf("%d\n", totalLength());
                        break;
 
                case CMD_PRINT:
                        printAll();
                        break;
 
                case CMD_EMPTY:
                        cin >> n;
                        for (int i = 0; i < n; i++)
                                add_empty();
                        break;
 
                case CMD_ADD:
                        while (scanf("%d%c", &k, &zn)) {
                                add_new(k);
                                if (zn == '\n') break;
                        }
                        break;
 
                case CMD_WYJMIJ:
                        cin >> n;
                        for (int i = 0; i < n; i++) {
                                wyjmij();
                        }
                        cout << "\n";
                        break;
 
                case CMD_USUN:
                        cin >> k;
                        usun(k);
                        break;
 
                case CMD_ERROR:
                default:
                        break;
                }
 
        }
        return 0;
}