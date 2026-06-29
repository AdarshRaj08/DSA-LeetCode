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
    int totalsum = 0;
    void sumfunc(TreeNode* node, int sum)
    {
        if(node == NULL) return;

        sum = sum*10 + node->val;
        if(node->left == NULL && node->right == NULL)
        {
            totalsum += sum;
            return;
        }
        sumfunc(node->left,sum);
        sumfunc(node->right,sum);
        return;

    }
    int sumNumbers(TreeNode* root) {
        sumfunc(root,0);
        return totalsum;
    }
};