#include<bits/stdc++.h>
using namespace std;
// Day-1:Pascal Triangle
vector<vector<int>> PascalTriangle(int n)
{
    vector<vector<int>> ans(n);
    for (int i = 0; i < n; i++)
    {
        ans[i].resize(i + 1);
        ans[i][0] = ans[i][i] = 1;
        for (int j = 1; j < i; j++)
        {
            ans[i][j] = ans[i - 1][j - 1] + ans[i - 1][j];
        }
    }
    return ans;
}
int main()
{
    int n;
    cin >> n;
    vector<vector<int>> ans;
    ans = PascalTriangle(n);
    for (auto i : ans)
    {
        for (auto j : i)
        {
            cout << j << " ";
        }
        cout << endl;
    }
}