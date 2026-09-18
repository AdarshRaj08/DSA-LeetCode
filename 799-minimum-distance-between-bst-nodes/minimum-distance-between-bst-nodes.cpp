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
    void BST(TreeNode* root, int &prev, int &ans){
        if(!root) return;

        BST(root->left, prev,ans);

        if(prev != -1){
            int diff = abs(root->val -  prev);
            if(ans > diff)
            ans = diff;
        }
        
        prev = root->val;

        BST(root->right, prev, ans);

        return;

    }

    int minDiffInBST(TreeNode* root) {
        int ans = INT_MAX;
        int prev = -1;
        BST(root,prev,ans);
        return ans;
    }
};