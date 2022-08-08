class Solution {
public:
    bool isPalin(string s, int b, int e)
    {
        while(b<=e)
        {
            if(s[b++]!=s[e--])
                return false;
        }
        return true;
    }
    void funct(int ind, string s, vector<string>&res, vector<vector<string>>&ans)
    {
        if(ind==s.size())
        {
            ans.push_back(res);
            return;
        }
        for(int i=ind;i<s.size();i++)
        {
            if(isPalin(s, ind, i))
            {
                res.push_back(s.substr(ind, i-ind+1));
                funct(i+1, s, res, ans);
                res.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>>ans;
        vector<string>res;
        funct(0, s, res, ans);
        return ans;co
        
    }
};