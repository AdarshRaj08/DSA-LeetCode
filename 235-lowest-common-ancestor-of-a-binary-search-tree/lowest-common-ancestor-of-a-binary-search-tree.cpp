/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* ans = NULL;
    void helperfunc(TreeNode* node, TreeNode* p, TreeNode* q)
    {
        if(node == NULL) return ;
        if(node == p || node == q)
        {
            ans = node; return;
        }
        if(node->val < p->val)
            helperfunc(node->right,p,q);
        else if(node->val > q->val)
            helperfunc(node->left,p,q);
        else
        {
            ans = node; return;
        }
        return;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(p->val > q->val)
            helperfunc(root,q,p);
        else
            helperfunc(root,p,q);
        return ans;
    }
};