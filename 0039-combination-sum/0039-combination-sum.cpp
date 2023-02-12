class Solution {
    private:
    void findCombination(int ind,int target,vector<int> candidates,vector<vector<int>>& ans,vector<int> dp)
    {
        if(ind==candidates.size())
        {
            if(target==0)
            {
                ans.push_back(dp);
                
            }
            return;
        }
        if(candidates[ind]<=target)
        {
            dp.push_back(candidates[ind]);
            findCombination(ind,target-candidates[ind],candidates,ans,dp);
            dp.pop_back();
        }
        findCombination(ind+1,target,candidates,ans,dp);
      
    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> dp;
        findCombination(0,target,candidates,ans,dp);
        return ans ;
    }
};