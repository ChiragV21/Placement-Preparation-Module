class Solution {
public:
    void find(int ind, int target,vector<int>&candidate, vector<vector<int>>&ans, vector<int>&ds)
    {
        if(ind==candidate.size())
        {
            if(target==0)
            {
                ans.push_back(ds);
            }
            return;
        }
        if(candidate[ind]<=target)
        {
            ds.push_back(candidate[ind]);
            find(ind, target-candidate[ind], candidate, ans, ds);
            ds.pop_back();
        }
        
        find(ind+1, target, candidate, ans, ds);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>>ans;
        vector<int>ds;
        find(0, target,candidates, ans, ds);
        return ans;
    }
};