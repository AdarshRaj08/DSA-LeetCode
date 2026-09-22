class Solution {
public:
    void combination(vector<int>&candidates,vector<vector<int>>& ans, vector<int>&ds, int indx, int target){
        if(indx == candidates.size()){
            if(target == 0){
                ans.push_back(ds);
            }
            return;
        }

        // take
        if(candidates[indx] <= target){
            ds.push_back(candidates[indx]);
            combination(candidates, ans, ds, indx, target-candidates[indx]);
            ds.pop_back();
        }
        // leave

        combination(candidates,ans,ds, indx+1, target);
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int>ds;
        combination(candidates, ans, ds, 0, target);

     return ans;   
    }
};