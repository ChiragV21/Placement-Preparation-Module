class Solution {
public:
    string getPermutation(int n, int k) {
        int f=1;
        vector<int>v;
        for(int i=1;i<n;i++)
        {
            f*=i;
            v.push_back(i);
        }
        v.push_back(n);
        string ans="";
        k=k-1;
        while(true)
        {
            ans+=to_string(v[k/f]);
            v.erase(v.begin()+k/f);
            if(v.size()==0)
                break;
            k%=f;
            f=f/v.size();
        }
        return ans;
    }
};