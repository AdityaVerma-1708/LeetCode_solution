class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
    //approach 1:
        sort(nums.begin(),nums.end());
        return nums[nums.size() - k];
    }
};