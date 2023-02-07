class Solution {
    private: 
    void solve(vector<int> nums,vector<vector<int>> &ans,vector<int> output,int index,
          int size,set<vector<int>> &res)
    {
        if(index>=size)
        {
            sort(output.begin(),output.end());
            res.insert(output);
            return;
        }
        solve(nums,ans,output,index+1,size,res);
        int element = nums[index];
        output.push_back(element);
        solve(nums,ans,output,index+1,size,res);
    }
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> output;
        set<vector<int>> res;
        int index =0;
        int size = nums.size();
        solve(nums,ans,output,index,size,res);
           for (auto it = res.begin(); it != res.end(); it++) {
      ans.push_back( * it);
    }
        return ans ;
    }
};