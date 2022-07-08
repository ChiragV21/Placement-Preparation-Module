#include <bits/stdc++.h>
using namespace std;
// Brute force Approach
int findDuplicate(vector<int> &nums)
{
    int n = nums.size();
    int ans = -1;
    for (int i = 0; i < n - 1; i++)
    {
        bool found = false;
        for (int j = i + 1; j < n; j++)
        {
            if (nums[i] == nums[j])
            {
                ans = nums[i];
                found = true;
                break;
            }
        }
        if (found == true)
            break;
    }
    return ans;
}

// Better Approach
int findDuplicate(vector<int> &nums)
{
    int n = nums.size();
    sort(nums.begin(), nums.end());
    for (int i = 1; i < n; i++)
    {
        if (nums[i - 1] == nums[i])
        {
            return nums[i];
        }
    }
    return -1;
}

// Optimise Approach
int findDuplicate(vector<int> &nums)
{
    int n = nums.size();
    vector<int> freq(n + 1, 0);
    for (int i = 0; i < n; i++)
    {
        freq[nums[i]]++;
    }

    for (int i = 0; i <= n; i++)
    {
        if (freq[i] > 1)
        {
            return i;
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

    int ans = findDuplicate(arr);
    cout << ans << endl;
    return 0;
}
