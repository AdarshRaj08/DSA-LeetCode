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
    vector<int> rightSideView(TreeNode* root) {
        if(root == NULL) return {};
        queue<TreeNode*>q;
        q.push(root);
        vector<int>result;

        while(!q.empty())
        {
            int size = q.size();
            
            while(size--)
            {
                TreeNode* t = q.front();
                q.pop();

                if(size == 0) result.push_back(t->val);

                if(t->left != NULL)
                    q.push(t->left);
                if(t->right != NULL)
                    q.push(t->right);
            }
        }
        return result;
    }
};