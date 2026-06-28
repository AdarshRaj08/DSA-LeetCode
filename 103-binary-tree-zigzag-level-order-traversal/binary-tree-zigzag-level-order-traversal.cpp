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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(root == NULL)
            return {};

        vector<vector<int>> res;
        queue<TreeNode*>q;
        q.push(root);

        bool leftToRight = true;
        while(!q.empty())
        {
            
            int size = q.size();
            vector<int>temp(size);
            int first = 0;
            int last = size-1;

            while(size--)
            {
                TreeNode* t = q.front();
                q.pop();

                if(t->left != NULL)
                    q.push(t->left);
                if(t->right != NULL)
                    q.push(t->right);
                
                if(leftToRight)
                {
                    temp[first] = t->val;
                    first++;
                }
                else
                {
                    temp[last] = t->val;
                    last--;
                }
            }
            res.push_back(temp);
            leftToRight = !leftToRight;
        }
        return res;
    }
};