class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
    //approach 1: checking every elements neighbour O(n);
        int ans = -1;
        int i = 1;
        while(i<nums.size()){
            if(nums[i] != nums[i-1]){
                return nums[i-1];
            }
            i = i+2;
        }
        if(ans == -1){
            ans = nums.back();
        }
        return ans;

    }
};