class Solution {
public:
    int minDifference(vector<int>& nums) {
        if(nums.size() <= 4){
            return 0;
        }

        sort(nums.begin(),nums.end());

        int ans = INT_MAX;
        int i = nums.size() - 1 - 3;
        while(i < nums.size()){
            ans = min(ans,nums[i] - nums[3 - (nums.size() - 1 - i)]);
            i++;
        }

        return ans;
    }
};