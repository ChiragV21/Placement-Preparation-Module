#include <bits/stdc++.h>
using namespace std;
// Problem:4 Sum
vector<vector<int>> fourSum(vector<int> &nums, int target)
{
    sort(nums.begin(), nums.end());
    int n = nums.size();
    set<vector<int>> s;
    for (int i = 0; i < n - 3; i++)
    {
        for (int j = i + 1; j < n - 2; j++)
        {
            int l = j + 1;
            int r = n - 1;
            while (l < r)
            {
                long long sum = (long long)nums[i] + nums[j] + nums[l] + nums[r];
                if (sum == target)
                {
                    vector<int> res;
                    res.push_back(nums[i]);
                    res.push_back(nums[j]);
                    res.push_back(nums[l]);
                    res.push_back(nums[r]);
                    s.insert(res);
                    l++;
                    r--;
                }

                else if (sum < target)
                    l++;

                else
                    r--;
            }
        }
    }

    vector<vector<int>> ans(s.begin(), s.end());
    return ans;
}

// without using set

vector<vector<int>> fourSum(vector<int> &nums, int target)
{
    vector<vector<int>> ans;
    if (nums.size() == 0)
        return ans;
    sort(nums.begin(), nums.end());
    int n = nums.size();
    for (int i = 0; i < n - 3; i++)
    {
        for (int j = i + 1; j < n - 2; j++)
        {
            int newtarget = target - nums[j] - nums[i];
            int l = j + 1;
            int r = n - 1;
            while (l < r)
            {
                int two_sum = nums[l] + nums[r];

                if (two_sum < newtarget)
                {
                    l++;
                }

                else if (two_sum > newtarget)
                {
                    r--;
                }

                else
                {
                    vector<int> res(4, 0);
                    res[0] = nums[i];
                    res[1] = nums[j];
                    res[2] = nums[l];
                    res[3] = nums[r];
                    ans.push_back(res);

                    while (l < r and nums[l] == res[2])
                        l++;

                    while (l < r and nums[r] == res[3])
                        r--;
                }
            }
            while (j + 1 < n and nums[j + 1] == nums[j])
                j++;
        }
        while (i + 1 < n and nums[i + 1] == nums[i])
            i++;
    }

    return ans;
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

    int target;
    cin >> target;
    vector<vector<int>> ans = threeSum(arr);
    for (auto i : ans)
    {
        for (auto j : i)
        {
            cout << j << " ";
        }
    }
    return 0;
}