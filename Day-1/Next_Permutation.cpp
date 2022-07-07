#include <bits/stdc++.h>
using namespace std;
// Day-1:Next Permutation
void nextPermutation(vector<int> &nums)
{
    int n = nums.size();
    int k, l;
    for (k = n - 2; k >= 0; k--)
    {
        if (nums[k] < nums[k + 1])
        {
            break;
        }
    }

    if (k < 0)
        reverse(nums.begin(), nums.end());

    else
    {
        for (l = n - 1; l > k; l--)
        {
            if (nums[l] > nums[k])
            {
                break;
            }
        }
        swap(nums[l], nums[k]);
        reverse(nums.begin() + k + 1, nums.end());
    }
}

int main()
{
    // Chirag Varshney:1900290130052
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    nextPermutation(arr);
    for (auto i : arr)
    {
        cout << i << " ";
    }
    return 0;
}