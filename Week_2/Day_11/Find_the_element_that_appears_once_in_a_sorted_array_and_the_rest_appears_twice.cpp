class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        if(nums.size() == 1)
            return nums[0];
        int l = 0, r = nums.size()-1;
        while(l<=r){
            int mid = (l+r)/2;
            if(mid == 0 && mid+1<nums.size() && nums[mid+1] != nums[mid])
                return nums[mid];
            if(mid == nums.size()-1 && mid-1>=0 && nums[mid-1] != nums[mid])
                return nums[mid];
            if(mid>0 && nums[mid] != nums[mid-1] && mid<nums.size()-1 && nums[mid] != nums[mid+1])
                return nums[mid];
            if(mid & 1){
                if(nums[mid] == nums[mid-1])
                    l = mid+1;
                else
                    r = mid-1;
            }
            else{
                if(nums[mid] == nums[mid+1])
                    l = mid+1;
                else
                    r = mid-1;
            }
        }
        return -1;
        
        
    }
};