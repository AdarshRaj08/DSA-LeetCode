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
    bool findTarget(TreeNode* root, int k) {
        InOrder(root);

        int n = inorder.size();
        int i=0; int j=n-1;

        while(i < j)
        {
            if(inorder[i]->val + inorder[j]->val == k)
                return true;
            else if(inorder[i]->val + inorder[j]->val > k)
                j--;
            else 
                i++;
        }
        return false;
    }
};