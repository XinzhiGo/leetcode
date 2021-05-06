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

TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
{
    if(preorder.size() == 0 || inorder.size() == 0) return nullptr;
    TreeNode *root = new TreeNode(preorder[0]);
    int k = 0;
    while(inorder[k] != preorder[0]) k++;
    vector<int> pre_left(preorder.begin()+1,preorder.begin()+k+1);
    vector<int> pre_right(preorder.begin()+k+2,preorder.end());
    vector<int> in_left(inorder.begin(),inorder.begin()+k);
    vector<int> in_right(inorder.begin()+k+1,inorder.end());


    root->left = buildTree(pre_left,in_left);
    root->right = buildTree(pre_right,in_right);
    return root;

}