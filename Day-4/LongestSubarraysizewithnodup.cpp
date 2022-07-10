#include <bits/stdc++.h>
using namespace std;
// Problem:Longest Substring Without Repeating Characters
// Approach:Basically in create an set and store character if character is present in the set the linear increament the pointer l and 
// calculate the len and compare length and print maximum length.

int lengthOfLongestSubstring(string s)
{
    int l = 0;
    unordered_set<int> mpp;
    int len = 0;
    for (int r = 0; r < s.size(); r++)
    {
        if (mpp.find(s[r]) != mpp.end())
        {
            while (l < r and mpp.find(s[r]) != mpp.end())
            {
                mpp.erase(s[l]);
                l++;
            }
        }
        mpp.insert(s[r]);
        len = max(len, r - l + 1);
    }
    return len;
}

// Approach: This is Optimise Approach
//  step-1: basically create a map or frequency array so that it also store the character with frequency
//  step-2: Linearly Iterate for a string if check character is already present in the frequency array so you can skip the character
//  that no affect the length of the subarray

int lengthOfLongestSubstring(string s)
{
    vector<int> mpp(256, -1);
    int len = 0;
    int l = 0, r = 0;
    while (r < s.size())
    {
        if (mpp[s[r]] != -1)
            l = max(l, mpp[s[r]] + 1);
        mpp[s[r]] = r;
        len = max(len, r - l + 1);
        r++;
    }
    return len;
}

int main()
{
    string s;
    cin >> s;
    int ans = lengthOfLongestSubstring(s);
    cout << ans << endl;
    return 0;
}