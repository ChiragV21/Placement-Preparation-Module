#include <bits/stdc++.h>
using namespace std;
// Day-1:Kedane's Algorithms
int maxSubArray(vector<int> &nums)
{
    int ans = INT_MIN;
    int curr_sum = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        curr_sum += nums[i];
        ans = max(ans, curr_sum);
        if (curr_sum < 0)
            curr_sum = 0;
    }
    return ans;
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
    int ans = maxSubArray(arr);
    cout << ans << endl;
    return 0;
}