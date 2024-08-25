class Solution {
public:
//approach 1: using recurrsion  TLE
    // int solve(vector<int>& nums,int i,int n){
    //     if(i > n){
    //         return 0;
    //     }
    //     if(i == n){
    //         return nums[i];
    //     }

    //     return max(nums[i] + solve(nums,i+2,n) , solve(nums,i+1,n));
    // }

    // int rob(vector<int>& nums) {
    //     if(nums.size() == 1){
    //         return nums[0];
    //     }
    //     int n = nums.size();
    //     return max(solve(nums,0,n-2),solve(nums,1,n-1));
    // }

//appraoch 2: using memoization from nums.size()->0 (top bottom);
    int solve(vector<int>& nums,int i,int n,vector<int>& dp){
        if(i < n){
            return 0;
        }
        if(i == n){
            return nums[i];
        }

        if(dp[i] != -1){
            return dp[i];
        }
        return dp[i] = max(nums[i] + solve(nums,i-2,n,dp) , solve(nums,i-1,n,dp));
    }

    int rob(vector<int>& nums) {
        if(nums.size() == 1){
            return nums[0];
        }
        int n = nums.size();
        vector<int>dp1(n,-1);
        vector<int>dp2(n,-1);

        return max(solve(nums,n-1,1,dp1),solve(nums,n-2,0,dp2));
    }
};