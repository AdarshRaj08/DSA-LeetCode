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
    vector<TreeNode*>inorder;
    void InOrder(TreeNode* root)
    {
        if(root == NULL) return;
        InOrder(root->left);
        inorder.push_back(root);
        InOrder(root->right);
    }
    bool isValidBST(TreeNode* root) {
        InOrder(root);

        int n = inorder.size();

        for(int i=0; i<n-1; i++)
        {
            if(inorder[i]->val >= inorder[i+1]->val)
            {
                return false;
            }
        }
        return true;
    }
};