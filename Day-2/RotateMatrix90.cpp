#include <bits/stdc++.h>
using namespace std;
//Problem:RotateMatrix90
//Naive Approach
void rotate(vector<vector<int>> &matrix)
{
    int n = matrix.size();
    vector<vector<int>> arr(n, vector<int>(n, 0));
    for (int i = 0; i < matrix.size(); i++)
    {
        for (int j = 0; j < matrix[0].size(); j++)
        {
            arr[j][n - i - 1] = matrix[i][j];
        }
    }

    for (int i = 0; i < matrix.size(); i++)
    {
        for (int j = 0; j < matrix[0].size(); j++)
        {
            matrix[i][j] = arr[i][j];
        }
    }
}

//Better Approach
void rotate90(vector<vector<int>> &matrix)
{
    // Adjacent of the Matrix
    int n = matrix.size();
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            swap(matrix[i][j], matrix[j][i]);
        }
    }

    for (int i = 0; i < n; i++)
    {
        reverse(matrix[i].begin(), matrix[i].end());
    }
}
int main()
{
    int n;
    cin >> n;
    // Because matrix n*n
    vector<vector<int>> arr(n, vector<int>(n, 0));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> arr[i][j];
        }
    }
    // rotate(arr);
    rotate90(arr);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
