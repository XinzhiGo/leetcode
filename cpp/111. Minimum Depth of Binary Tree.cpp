#include <iostream>
#include <set>
#include <queue>
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


int minDepth(TreeNode *root)
{
    queue<TreeNode *> q;
    if(root!=nullptr) q.push(root);
    else return 0;
    int step = 1;

    while (!q.empty())
    {
        int size = q.size();
        for (int i = 0; i < size; i++)
        {
            TreeNode *front = q.front();
            q.pop();
            if (front->left == nullptr && front->right == nullptr)
            {
                return step;
            }
            if (front->left != nullptr)
                q.push(front->left);

            if (front->right != nullptr)
                q.push(front->right);
        }
        step++;
    }
    return step;
}