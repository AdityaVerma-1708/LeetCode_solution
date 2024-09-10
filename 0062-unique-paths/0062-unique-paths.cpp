class Solution {
public:

//appraoch 1: recurrsion  TLE @41/63
    // int solve(int i,int j,int m,int n){
    //     if(i == m-1 && j == n-1){
    //         return 1;
    //     }

    //     int count = 0;
    //     //right if possible
    //     if(j+1 < n){
    //         count = count + solve(i,j+1,m,n);
    //     }

    //     //down if possible
    //     if(i+1 < m){
    //         count = count + solve(i+1,j,m,n);
    //     }

    //     return count;
    // }

    // int uniquePaths(int m, int n) {
    //     return solve(0,0,m,n);
    // }

//appraoch 2: Dp 

    int solve(int i,int j,int m,int n,vector<vector<int>>&dp){
        if(i == m-1 && j == n-1){
            return 1;
        }

        if(dp[i][j] != -1){
            return dp[i][j];
        }

        int count = 0;
        //right if possible
        if(j+1 < n){
            count = count + solve(i,j+1,m,n,dp);
        }

        //down if possible
        if(i+1 < m){
            count = count + solve(i+1,j,m,n,dp);
        }

        return dp[i][j] = count;
    }

    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m,vector<int>(n,-1));

        return solve(0,0,m,n,dp);
    }
};