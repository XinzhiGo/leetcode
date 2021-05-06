#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int val;
    Node *left;
    Node *right;
    Node *next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node *_left, Node *_right, Node *_next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
void connect_two_root(Node *a, Node *b)
{
    if (a->left == nullptr)
        return;
    a->next = b;
    connect_two_root(a->left, a->right);
    connect_two_root(b->left, b->right);
    connect_two_root(a->right, b->left);
}

Node *connect(Node *root)
{
    if (root == nullptr)
        return nullptr;
    connect_two_root(root->left, root->right);
    return root;
}
