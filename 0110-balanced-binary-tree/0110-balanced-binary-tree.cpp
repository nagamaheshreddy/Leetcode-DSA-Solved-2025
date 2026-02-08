/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int dfs(TreeNode* root, bool &isBalanced){
        if(root==NULL)return 0;

        int left=dfs(root->left,isBalanced);
        int right=dfs(root->right,isBalanced);

        if(abs(right-left)>1)isBalanced=false;
        return 1+max(left,right);
    }
    bool isBalanced(TreeNode* root) {
        bool isBalanced=true;
    
        dfs(root,isBalanced);
        return isBalanced;
    }
};