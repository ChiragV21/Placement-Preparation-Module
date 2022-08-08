
#include<bits/stdc++.h>
using namespace std;
int minCoins(int coins[], int m, int V)
{
// base case
if (V == 0) return 0;

int res = INT_MAX;
for (int i=0; i<m; i++)
{
	if (coins[i] <= V)
	{
		int sub_res = minCoins(coins, m, V-coins[i]);

		if (sub_res != INT_MAX && sub_res + 1 < res)
			res = sub_res + 1;
	}
}
return res;
}

// Driver program to test above function
int main()
{
	int coins[] = {9, 6, 5, 1};
	int m = sizeof(coins)/sizeof(coins[0]);
	int V = 11;
	cout << "Minimum coins required is "
		<< minCoins(coins, m, V);
	return 0;
}
