class Solution {
public:
//approach 1: using recurrsion 
    int solve(vector<int>& nums,int i,int n){
        if(i > n){
            return 0;
        }
        if(i == n){
            return nums[i];
        }

        return max(nums[i] + solve(nums,i+2,n) , solve(nums,i+1,n));
    }

    int rob(vector<int>& nums) {
        if(nums.size() == 1){
            return nums[0];
        }
        int n = nums.size();
        return max(solve(nums,0,n-2),solve(nums,1,n-1));
    }
};