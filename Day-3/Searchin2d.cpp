#include <bits/stdc++.h>
using namespace std;
bool searchMatrix(vector<vector<int>> &matrix, int target)
{
    int m = matrix.size();    // rows
    int n = matrix[0].size(); // columns
    int l = 0, r = (m * n) - 1;
    while (l <= r)
    {
        int mid = l + (r - l) / 2;
        if (matrix[mid / n][mid % n] == target)
        {
            return true;
        }

        else if (matrix[mid / n][mid % n] > target)
        {
            r = mid - 1;
        }

        else
        {
            l = mid + 1;
        }
    }
    return false;
}

int main()
{
    int m, n;
    cin >> m >> n;
    vector<vector<int>> arr(m, vector<int>(n, 0));
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> arr[i][j];
        }
    }

    int target;
    cin >> target;

    if (searchMatrix(arr, target))
        cout << target << " is present in the Matrix" << endl;
    else
        cout << target << " is not present in the Matrix" << endl;

    return 0;
}
