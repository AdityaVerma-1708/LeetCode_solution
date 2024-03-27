class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
    //approach 1:
        int ans = 0;
        for(int i = 0;i<nums.size();i++){
            long long prod = 1;
            for(int j = i;j<nums.size();j++){
                prod = prod * nums[j];
                if(prod < k){
                    ans++;
                }
                else if (prod >=k ){
                    break;
                }
            }
        } 
        return ans;
    }
};