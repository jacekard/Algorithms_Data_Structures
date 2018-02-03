#include <cstdio>
 
class Node
{
public:
        Node *left, *right, *parent;
        int key;
        Node(int key) : left(NULL), right(NULL), key(key)
        { }
};
 
void insert(Node *N, int key)
{
        if (N->key == key)
                return;
        if (N->key < key)
                if (N->right)
                        insert(N->right, key);
                else
                {
                        N->right = new Node(key);
                        N->right->parent = N;
                }
        else
                if (N->left)
                        insert(N->left, key);
                else
                {
                        N->left = new Node(key);
                        N->left->parent = N;
                }
}
 
Node* search(Node* N, int key)
{
        if (N == NULL)
                return NULL;
        if (N->key == key)
                return N;
        if (N->key < key)
                return search(N->right, key);
        return search(N->left, key);
}
 
int l_wierzch(Node *n) {
        int suma = 0;
        while (n != NULL) {
                suma++;
                n = n->parent;
        }
        return suma;
}
 
int suma_lisci(Node *n) {
        if (n == NULL) return 0;
        if (!n->left && !n->right) return n->key;
 
        int a = suma_lisci(n->right);
        int b = suma_lisci(n->left);
        return a + b;
 
}
 
void wierzch_preorder(Node *n) {
        if (n == NULL) return;
 
        wierzch_preorder(n->left);
        printf("%d ", n->key);
        wierzch_preorder(n->right);
}
 
int max_klucz(Node *n) {
        while (n != NULL) {
                if (!n->right)  {
                        return n->key;
                }
                n = n->right;
        }
        return 0;
}
 
int main()
{
        char cmd;
        int key;
        Node *root = NULL, *out;
 
        while (scanf("%c %d", &cmd, &key) > 0)
        {
                if (cmd == 'I')
                        if (root != NULL)
                                insert(root, key);
                        else {
                                root = new Node(key);
                                root->parent = NULL;
                        }
                else if (cmd == 'S')
                        out = search(root, key);
                // tu należy dopisać pozostałe funkcje
                else if (cmd == 'D') {
                        Node *tmp = search(root, key);
                        if (tmp == NULL)
                                printf("-\n");
                        else {
                                printf("%d",l_wierzch(tmp));
                                printf("\n");
                        }
                }
                else if (cmd == 'V') {
                        Node *tmp = search(root, key);
                        if (tmp == NULL)
                                printf("-\n");
                        else {
                                printf("%d", suma_lisci(tmp));
                                printf("\n");
                        }
                }
                else if (cmd == 'E') {
                        Node *tmp = search(root, key);
                        if (tmp == NULL)
                                printf("-\n");
                        else {
                                wierzch_preorder(tmp);
                                printf("\n");
                        }
                }
                else if (cmd == 'X') {
                        Node *tmp = search(root, key);
                        if (tmp == NULL)
                                printf("-\n");
                        else {
                                printf("%d", max_klucz(tmp));
                                printf("\n");
                        }
                }
        }
        return 0;
}