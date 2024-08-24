class Solution {
public:

//approach 1: using recurrsion TLE at 21 TC
    // void solve(int n,int &ans){
    //     if(n == 0){
    //         ans++;
    //         return;
    //     }
    //     else if(n<0){
    //         return;
    //     }

    //     solve(n-1,ans,n);
    //     solve(n-2,ans,n);
    // }

    // int climbStairs(int n) {
    //     int ans = 0;
    //     solve(n,ans);
    //     return ans;
    // }

//appraoch 2: we should optimize it using the DP 
    //basically there are some subproblems which are repeating somewhere 
    //we should use the memory for saving the prev solved subproblems
      
    //for that we can use array or map anything
    


//appraoch 2:   using memoization  

    int solve(vector<int>& dp,int n){
        if(n <= 2){
            return dp[n] = n;
        }
        if(dp[n] != -1){
            return dp[n];
        }

        return dp[n] = solve(dp,n-1) + solve(dp,n-2);
    }

    int climbStairs(int n){
        vector<int>dp(n+1,-1);
        return solve(dp,n);
    }    
};