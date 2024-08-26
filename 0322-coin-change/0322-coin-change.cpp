class Solution {
public:

//approach 1: using recurrsion TLE 
    // int solve(vector<int>& coins,int amount,long long curr,long long ans){
    //     if(curr > amount){
    //         return INT_MAX;
    //     }
    //     if(curr == amount){
    //         return ans;
    //     }

    //     int count = INT_MAX;
    //     for(int i = 0;i<coins.size();i++){
    //         count = min(solve(coins,amount,curr+coins[i],ans+1),count);
    //     }
    //     return count;

    // }

    // int coinChange(vector<int>& coins, int amount) {
    //     if(solve(coins,amount,0,0) == INT_MAX){
    //         return -1;
    //     }
    //     return solve(coins,amount,0,0);
    // }

//approach 2: dp with memoization top down 
    
    int solve(vector<int>& coins,int amount,vector<int>& dp){
        if(amount < 0){
            return INT_MAX;
        }
        if(amount == 0){
            return 0;
        }

        if(dp[amount] != -1){
            return dp[amount];
        }

        int count = INT_MAX;
        for(int i = 0;i<coins.size();i++){
            if(solve(coins,amount-coins[i],dp) == INT_MAX){
                continue;
            }
            count = min(count, 1 + solve(coins,amount-coins[i],dp));
        }

        return dp[amount] = count;
    }

    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(10001,-1);
        if(solve(coins,amount,dp) == INT_MAX){
            return -1;
        }
        return solve(coins,amount,dp);
    }
};