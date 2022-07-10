#include <bits/stdc++.h>
using namespace std;
// Problem:Count Subarrays with Xor as K
//Brute Force Approach , TC:O(n^2)
int subarraysXor(vector<int> &arr, int x)
{
    int n = arr.size();
    int ans = 0; // count of the Subarray
    for (int i = 0; i < n; i++)
    {
        int xr = 0;
        for (int j = i; j < n; j++)
        {
            xr = xr ^ arr[j];
            if (xr == x)
                ans++;
        }
    }
    return ans;
}

//Optimised Approach , TC:O(n)
int OptimisesubarraysXor(vector<int> &arr, int x)
{
    int n = arr.size();
    int ans = 0; // count of the Subarray
    int prefixor = 0;
    unordered_map<int, int> mp;
    for (int i = 0; i < n; i++)
    {
        prefixor = prefixor ^ arr[i];

        if (prefixor == x)
            ans++;

        if (mp.find(prefixor ^ x) != mp.end())
        {
            ans += mp[prefixor ^ x];
        }

        mp[prefixor]++;
    }
    return ans;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        vector<int> arr(n);
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }

        int res = subarraysXor(arr, k);
        int res_1 = OptimisesubarraysXor(arr, k);
        cout << res << endl;
    }
    return 0;
}