#include <bits/stdc++.h>
using namespace std;
// Day-1:Best Time to Buy and Sell Stock
// Brurte Approach:TC:O(n^2)
int maxProfit(vector<int> &prices)
{
    int maxProfit = 0;
    int n = prices.size();
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (prices[j] > prices[i])
            {
                maxProfit = max(maxProfit, prices[j] - prices[i]);
            }
        }
    }
    return maxProfit;
}

// Optimise Approach:TC:O(n)
int maxProfits(vector<int> &prices)
{
    int maxProfit = 0;
    int n = prices.size();
    int mini = INT_MAX;
    for (int i = 0; i < n; i++)
    {
        mini = min(mini, prices[i]);
        maxProfit = max(maxProfit, prices[i] - mini);
    }
    return maxProfit;
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

    int ans = maxProfit(arr);
    cout << ans << endl;
    return 0;
}