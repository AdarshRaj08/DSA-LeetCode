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
    vector<vector<int>> result;
    void tempfunc(TreeNode* node, vector<int>&sum,int addsum, int targetSum)
    {
        if(node == NULL) return;

        sum.push_back(node->val);
        addsum += node->val;
        if(node->left == NULL && node->right == NULL)
        {
            if(addsum == targetSum)
                result.push_back(sum);
                sum.pop_back();
                return;
        }
        tempfunc(node->left, sum,addsum, targetSum);
        tempfunc(node->right,sum,addsum, targetSum);
        sum.pop_back();
        return;
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<int>path;
        tempfunc(root,path,0,targetSum);
        return result;
    }
};