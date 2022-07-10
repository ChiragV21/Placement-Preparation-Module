#include <bits/stdc++.h>
using namespace std;
int majorityElement(vector<int> &nums)
{
    int n=nums.size();
    unordered_map<int, int> mp;
    for (int i = 0; i < n; i++)
    {
        mp[nums[i]]++;
    }

    for (auto it : mp)
    {
        if (it.second > n / 2)
        {
            return it.first;
        }
    }
    return -1;
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
    int ans = majorityElement(arr);
    cout << ans << endl;
    return 0;
}
