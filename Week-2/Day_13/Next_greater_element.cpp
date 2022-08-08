class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int> st;
        unordered_map<int, int> nge;
        
        int n = nums2.size();
        for (int i = 0; i < n; i++) {
            while (!st.empty() && st.top() < nums2[i]) {
                nge[st.top()] = nums2[i];
                st.pop();
            }
            
            st.push(nums2[i]);
        }
        
        while (! st.empty()) {
            nge[st.top()] = -1;
            st.pop();
        }
        
        for (int i = nums1.size()-1; i >= 0; i--) {
            nums1[i] = nge[nums1[i]];
        }
        
        return nums1;
        
    }
};