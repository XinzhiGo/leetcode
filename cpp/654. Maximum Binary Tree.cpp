#include<bits/stdc++.h>
using namespace std;

struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };

int find_max(vector<int> v){
    int max_num = v[0];
    int index = 0;
    for(int i = 1;i < v.size();i++){
        if(max_num < v[i]){
            max_num = v[i];
            index = i;
        }
    }
    return index;
}
TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
    if(nums.size() == 0) return nullptr;
    
    TreeNode *root = new TreeNode;
    int index = find_max(nums);
    root->val = nums[index];
    
    vector<int> left(nums.begin(),nums.begin()+index);
    vector<int> right(nums.begin()+index+1,nums.end());
    root->left = constructMaximumBinaryTree(left);
    root->right = constructMaximumBinaryTree(right);
    return root;
 } 