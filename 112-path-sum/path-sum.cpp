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
    bool ans = false;
    void helperfunc(TreeNode* node,int sum, int target)
    {
        if(node == NULL) return;
        sum += node->val;
        if(node->left == NULL && node->right == NULL)
        {
            if(sum == target) ans = true;
        }
        helperfunc(node->left, sum , target);
        helperfunc(node->right, sum, target);
        
        return;
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        helperfunc(root,0,targetSum);
        return ans;
    }
};