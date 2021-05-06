#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

TreeNode *create_tree(int inl, int inr, int postl, int postr, vector<int> &in, vector<int> &post)
{
    if (inl > inr)
        return nullptr;
    TreeNode *root = new TreeNode(post[postr]);
    int k = inl;
    while (in[k] != root->val)
        k++;

    root->left = create_tree(inl, k - 1, postl, postl + k - inl - 1, in, post);
    root->right = create_tree(k + 1, inr, postl + k - inl, postr - 1, in, post);
    return root;
}
TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder)
{
    return create_tree(0, inorder.size() - 1, 0, postorder.size() - 1, inorder, postorder);
}