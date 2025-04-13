class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        long long maxi = 0;
        long long ans = 0;
        long long diff = 0;

        for(int i = 0;i<nums.size();i++){
            ans = max(ans,diff*nums[i]);
            diff = max(diff,(long long)maxi - nums[i]);
            maxi = max(maxi,(long long)nums[i]);
        }
        return ans;
    }
};