#include <bits/stdc++.h>
using namespace std;
// Day-1:Sort 0,1,2
void sortColors(vector<int> &nums)
{
    int low = 0, mid = 0, end = nums.size() - 1;
    while (mid <= end)
    {
        if (nums[mid] == 0)
        {
            swap(nums[low], nums[mid]);
            low++;
            mid++;
        }

        else if (nums[mid] == 1)
        {
            mid++;
        }

        else
        {
            swap(nums[mid], nums[end]);
            end--;
        }
    }
}

// Another Approach

void sortColor(vector<int> &nums)
{
    int cnt_0 = 0;
    int cnt_1 = 0;
    int cnt_2 = 0;
    int n = nums.size();
    for (int i = 0; i < n; i++)
    {
        if (nums[i] == 0)
            cnt_0++;
        else if (nums[i] == 1)
            cnt_1++;
        else
            cnt_2++;
    }

    nums.clear();
    while (cnt_0)
    {
        nums.push_back(0);
        cnt_0--;
    }

    while (cnt_1)
    {
        nums.push_back(1);
        cnt_1--;
    }

    while (cnt_2)
    {
        nums.push_back(2);
        cnt_2--;
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
    sortColors(arr);
    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}