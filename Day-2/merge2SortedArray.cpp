#include <bits/stdc++.h>
using namespace std;
// without using any extraspace
void merge(vector<int> &nums1, vector<int> &nums2)
{
    int n = nums1.size();
    int m = nums2.size();
    for (int i = 0; i < n; i++)
    {
        if (nums1[i] > nums2[0])
        {
            swap(nums1[i], nums2[0]);
        }

        int first = nums2[0];
        int k;
        for (k = 1; k < m and nums2[k] < first; k++)
        {
            nums2[k - 1] = nums2[k];
        }
        nums2[k - 1] = first;
    }
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> arr1(n);
    vector<int> arr2(m);
    for (int i = 0; i < n; i++)
    {
        cin >> arr1[i];
    }

    for (int i = 0; i < m; i++)
    {
        cin >> arr2[i];
    }

    merge(arr1, arr2);

    for (int i = 0; i < n; i++)
    {
        cout << arr1[i] << " ";
    }

    for (int i = 0; i < m; i++)
    {
        cout << arr2[i] << " ";
    }
    return 0;
}
