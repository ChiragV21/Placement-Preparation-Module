#include <bits/stdc++.h>
using namespace std;
struct Item
{
    double weight;
    double value;
};

bool compare(Item i1, Item i2)
{
    double a = (double)i1.value / (double)i1.weight;
    double b = (double)i2.value / (double)i2.weight;
    return a > b;
}

double fractionalKnapsack(int W, Item arr[], int n)
{
    sort(arr, arr + n, compare);
    int currweight = 0;
    double ans = 0.0;
    for (int i = 0; i < n; i++)
    {
        if (currweight + arr[i].weight <= W)
        {
            currweight += arr[i].weight;
            ans += arr[i].value;
        }
        else
        {
            int rem = W - currweight;
            ans += (double)rem * (arr[i].value / (double)arr[i].weight);
            break;
        }
    }
    return ans;
}

int main()
{
    int n, W;
    cin >> n >> W;
    double weight[n], value[n];
    for (int i = 0; i < n; i++)
    {
        cin >> weight[i];
    }

    for (int i = 0; i < n; i++)
    {
        cin >> value[i];
    }

    Item arr[n];
    for (int i = 0; i < n; i++)
    {
        arr[i].value = value[i];
        arr[i].weight = weight[i];
    }

    double ans = fractionalKnapsack(W, arr, n);
    cout << ans << endl;
    return 0;
}