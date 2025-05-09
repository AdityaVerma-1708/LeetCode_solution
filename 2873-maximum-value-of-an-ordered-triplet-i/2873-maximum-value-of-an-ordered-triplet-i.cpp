class Solution {
public:
//approach 1:
    long long maximumTripletValue(vector<int>& nums) {
        long long ans = 0;
        for(int i = 0;i<nums.size();i++){
            for(int j = i+1;j<nums.size();j++){
                for(int k = j+1;k<nums.size();k++){
                    long long val = (long long)(nums[i] - nums[j])*nums[k];
                    ans = max(ans,val);
                }
            }
        }
        return ans;
    }
};