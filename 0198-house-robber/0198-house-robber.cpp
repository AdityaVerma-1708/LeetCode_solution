class Solution {
public:
//approach 1: recurrsion

    // int solve(vector<int>& nums,int i,int ans){
    //     if(i == nums.size()-1){
    //         return ans + nums[i]; 
    //     }
    //     if(i+2 >= nums.size()){
    //         return ans + nums[i];
    //     }
        
    //     if(i == -1){
    //         int maxi = 0;
    //         for(int j = 0;j<nums.size();j++){
    //             maxi = max(solve(nums,j,ans),maxi);
    //         }
    //         return maxi;
    //     }

    //     else{
    //         int maxi = 0;
    //         for(int j = i+2;j<nums.size();j++){
    //             maxi = max(solve(nums,j,ans+nums[i]),maxi);
    //         }
    //         return maxi;
    //     }
    // }

    // int rob(vector<int>& nums) {
    //     return solve(nums,-1,0);
    // }



//appraoch 2: top bottom dp (memoization) from 0 to end

    // int solve(vector<int>& nums,int i,vector<int>& dp){
    //     if(i >= nums.size()){
    //         return 0;
    //     }

    //     if(dp[i] != -1){
    //         return dp[i];
    //     }

    //     return dp[i] = max(nums[i] + solve(nums,i+2,dp) , solve(nums,i+1,dp));

    // }

    // int rob(vector<int>& nums) {
    //     vector<int> dp(nums.size(),-1);
    //     return solve(nums,0,dp);
    // }

//approach 3: memoizaton from nums.size() to 0

    // int solve(vector<int>& nums,int i,vector<int>& dp){
    //     if(i < 0){
    //         return 0;
    //     }

    //     if(i == 0){
    //         return nums[i];
    //     }
        
    //     if(dp[i] != -1){
    //         return dp[i];
    //     }
        

    //     return dp[i] = max(nums[i] + solve(nums,i-2,dp) , solve(nums,i-1,dp));

    // }

    // int rob(vector<int>& nums) {
    //     vector<int> dp(nums.size(),-1);
    //     return solve(nums,nums.size()-1,dp);
    // }

//appraoch 4: bottom up DP (tabular)    

    int rob(vector<int>& nums) {
        if(nums.size() == 1){
            return nums[0];
        }
        vector<int> dp(nums.size()+1,-1);
        dp[0] = nums[0];
        dp[1] = nums[1];

        for(int i = 2;i<nums.size();i++){
            int maxi = 0;
            for(int j = i-2;j >= 0;j--){
                maxi = max(nums[i] + dp[j],maxi);
            }
            dp[i] = maxi;
        }

        int ans = 0;
        for(int i = 0;i<dp.size();i++){
            ans = max(ans,dp[i]);
        }
        return ans;
        return dp[nums.size()-1];
    }
};