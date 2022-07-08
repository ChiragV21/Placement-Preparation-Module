#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> merge(vector<vector<int>> &intervals)
{
    vector<vector<int>> mergeInterval;
    if (intervals.size() == 0)
        return mergeInterval;

    sort(intervals.begin(), intervals.end());
    vector<int> temp = intervals[0];
    for (auto it : intervals)
    {
        if (it[0] <= temp[1])
        {
            temp[1] = max(temp[1], it[1]);
        }
        else
        {
            mergeInterval.push_back(temp);
            temp = it;
        }
    }
    mergeInterval.push_back(temp);
    return mergeInterval;
}

int main()
{
    int n;
    cin >> n;
    vector<vector<int>> arr(n, vector<int>(2, 0));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            cin >> arr[i][j];
        }
    }

    vector<vector<int>> ans = merge(arr);
    for (int i = 0; i < ans.size(); i++)
    {
        for (int j = 0; j < 2; j++)
        {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
