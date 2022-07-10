#include <bits/stdc++.h>
using namespace std;
double myPow(double x, int n)
{
    double ans = 1.0;
    long long y = n;
    if (y < 0)
        y = y * (-1);

    while (y > 0)
    {
        if (y % 2 != 0)
        {
            ans = ans * x;
            y = y - 1;
        }

        else
        {
            x = x * x;
            y = y / 2;
        }
    }
    if (n < 0)
        return (double)(1.0) / (double)ans;
    return ans;
}

int main()
{
    double x;
    int n;
    cin >> x >> n;
    double ans = myPow(x, n);
    cout << ans << endl;
    return 0;
}
