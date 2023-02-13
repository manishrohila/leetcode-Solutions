class Solution {
    private:
    bool palindrome(string s , int st ,int e)
    {
       while (st <= e) {
      if (s[st++] != s[e--])
        return false;
    }
    return true;
  }
    void partition(int index,string s,vector<string> &path,vector<vector<string>> &res)
    {
        if(index==s.size())
        {
            res.push_back(path);
            return;
        }
        for(int i =index;i<s.size();++i)
        {
            if(palindrome(s,index,i))
            {
                path.push_back(s.substr(index,i-index+1));
                partition(i+1,s,path,res);
                path.pop_back();
            }
        }
    }
    
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> res;
        vector<string> path;
        partition(0,s,path,res);
        return res;
    }
};