int Solution::findMedian(vector<vector<int> > &a) {
    vector<int>v;
    for(int i=0;i<a.size();i++)
    {
        for(int j=0;j<a[0].size();j++)
        {
            v.push_back(a[i][j]);
        }
    }
    int n=v.size();
    int ans;
    sort(v.begin(), v.end());
    if(n%2==1)
    {
        ans=(n/2);
    }
    else
    {
        ans=n/2;
    }
    return v[ans];
}
