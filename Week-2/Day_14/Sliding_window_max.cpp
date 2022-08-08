class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        if(k == 1) return nums;
        
        int n = nums.size();
        vector<int> output;
        deque<int> index;
        
        for(int l = 0, r = 0; r < n; r++){
            while(!index.empty() and nums[index.back()] < nums[r]){
                index.pop_back();
            }
            index.push_back(r);
            
            if(l > index.front()) index.pop_front();
            
            if(r + 1 >= k){
                output.push_back(nums[index.front()]);
                l++;
            }
        }
        return output;
    }
};