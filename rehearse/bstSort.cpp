#include <iostream>
using namespace std;

struct Node{
    Node (int v) : val(v), left(nullptr), right(nullptr) {
    }
    int val;
    Node *left;
    Node *right;
};

Node* insert(Node* t, int val) {
    if (!t)
        return new Node(val);
    if (t->val > val)
        t->left = insert(t->left, val);
    else
        t->right = insert(t->right, val);
    return t;
}

void inorder(Node* t) {
    if (!t)
        return;
    inorder(t->left);
    cout << t->val << endl;
    inorder(t->right);
}

int main() {
    Node* T = nullptr;
    srand(time(0));
    for (int i = 0; i < 20; i++) {
        T = insert(T, rand() % 10000);
    }
    inorder(T);
    return 0;
}
