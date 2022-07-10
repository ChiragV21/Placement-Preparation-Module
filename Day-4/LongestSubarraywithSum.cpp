#include <bits/stdc++.h>
using namespace std;
// Problem:Longest Subarray Sum
int maxLen(vector<int> &arr, int n)
{
    // Your code here
    int target = 0;
    int currsum = 0;
    int res = 0;
    unordered_map<int, int> mp;
    for (int i = 0; i < arr.size(); i++)
    {
        currsum += arr[i];
        if (currsum == target)
            res = i + 1;

        if (mp.find(currsum - target) != mp.end())
        {
            res = max(res, i - mp[currsum - target]);
        }

        if (mp.find(currsum) == mp.end())
        {
            mp.insert({currsum, i});
        }
    }
    return res;
}

int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int res = maxLen(arr);
    cout << res << endl;
    return 0;
}