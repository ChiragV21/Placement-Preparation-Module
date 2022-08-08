class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int> ns;
        vector<int> ps;
        previousSmaller(heights,ps,n);
        nextSmaller(heights,ns,n);

        long long int maxArea = 0;     
        for(int i=0; i<n; i++)
        {
            long long int area = (ns[i] - ps[i] - 1) * heights[i];
            maxArea = max(maxArea, area);
        }
        return maxArea;
    }
    void previousSmaller(vector<int> &heights, vector<int> &ps, int n)
    {

        stack<pair<int, int>> stk;
        stk.push({-1,-1});

        for(int i=0; i<n; i++)
        {
            while(stk.top().first >= heights[i])
                stk.pop();
            ps.push_back(stk.top().second);
            stk.push({heights[i], i});
        }
    }
    void nextSmaller(vector<int> &heights, vector<int> &ns, int n)
    {
        stack<pair<int, int>> stk;
        stk.push({-1,n});
        for(int i=n-1; i>=0; i--)
        {
            while(stk.top().first >= heights[i])
                stk.pop();
            ns.push_back(stk.top().second);
            stk.push({heights[i], i});
        }
        reverse(ns.begin(), ns.end());
    }
};