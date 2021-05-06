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

int getMin(TreeNode *root)
{
    while (root->left != nullptr)
        root = root->left;
    return root->val;
}
TreeNode *deleteNode(TreeNode *root, int key)
{
    if (root == nullptr)
        return nullptr;
    //如果是葉結點，則直接刪除
    //如果是只有左孩子或者只有右孩子，則讓其左孩子或者右孩子替換，將其左孩子右孩子刪除
    //如果左右孩子都存在，則用其最右下角的代替其

    if (key == root->val)
    {
        if (root->left == nullptr)
            return root->right;
        if (root->right == nullptr)
            return root->left;

        root->val = getMin(root->right);
        root->right = deleteNode(root->right, root->val);
    }
    if (key < root->val)
    {
        root->left = deleteNode(root->left, key);
    }
    if (key > root->val)
    {
        root->right = deleteNode(root->right, key);
    }

    return root;
}