class Solution {
public:
//approach 1: using recurrsion --> TLE @ 36/143

    // bool solve(vector<int> nums,int i,int sum,int curr){
    //     if(curr == sum){
    //         return true;
    //     }
        
    //     if(i >= nums.size()){
    //         return false;
    //     }

    //     if(nums[i] + curr <= sum){
    //         //include or exclude 
    //         return solve(nums,i+1,sum,curr + nums[i]) || solve(nums,i+1,sum,curr);
    //     }
    //     else{
    //         return solve(nums,i+1,sum,curr);
    //     }

    // }

    // bool canPartition(vector<int>& nums) {
    //     //find the sum;
    //     int sum = 0;
    //     for(int i = 0;i<nums.size();i++){
    //         sum = sum + nums[i];
    //     }
    //     if(sum % 2 != 0){
    //         return false;
    //     }
    //     else{
    //         return solve(nums,0,sum/2,0);
    //     }
    // }

//approach 2: memozation;

    bool solve(vector<int> nums,int i,int sum,int curr,vector<vector<int>>& dp){
        if(curr == sum){
            return dp[i][curr] = true;
        }

        if(i >= nums.size()){
            return dp[i][curr] = false;
        }

        if(dp[i][curr] != -1){
            return dp[i][curr];
        }

        if(curr + nums[i] <= sum){
            return dp[i][curr] = solve(nums,i+1,sum,curr + nums[i],dp) || solve(nums,i+1,sum,curr,dp);
        }
        else{
            return dp[i][curr] = solve(nums,i+1,sum,curr,dp);
        }
    }

    bool canPartition(vector<int>& nums) {
        //find the sum;
        int sum = 0;
        for(int i = 0;i<nums.size();i++){
            sum = sum + nums[i];
        }
        if(sum % 2 != 0){
            return false;
        }
        else{
            vector<vector<int>> dp(nums.size()+1,vector<int> ((sum/2)+1,-1));
            return solve(nums,0,sum/2,0,dp);
        }
    }

};