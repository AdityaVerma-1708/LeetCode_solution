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

//appraoch 2: Dp memoization start to end (bottom up)

    // int solve(int i,int j,int m,int n,vector<vector<int>>&dp){
    //     if(i == m-1 && j == n-1){
    //         return 1;
    //     }

    //     if(dp[i][j] != -1){
    //         return dp[i][j];
    //     }

    //     int count = 0;
    //     //right if possible
    //     if(j+1 < n){
    //         count = count + solve(i,j+1,m,n,dp);
    //     }

    //     //down if possible
    //     if(i+1 < m){
    //         count = count + solve(i+1,j,m,n,dp);
    //     }

    //     return dp[i][j] = count;
    // }

    // int uniquePaths(int m, int n) {
    //     vector<vector<int>> dp(m,vector<int>(n,-1));
    //     return solve(0,0,m,n,dp);
    // }


//appraoch 3: Dp memoization end to start (top down)

    // int solve(int m,int n,vector<vector<int>>&dp){
    //     if(m == 0 && n == 0){
    //         return 1;
    //     }

    //     if(dp[m][n] != -1){
    //         return dp[m][n];
    //     }

    //     int count = 0;
    //     //right if possible
    //     if(n-1 >= 0){
    //         count = count + solve(m,n-1,dp);
    //     }

    //     //down if possible
    //     if(m-1 >= 0){
    //         count = count + solve(m-1,n,dp);
    //     }

    //     return dp[m][n] = count;
    // }

    // int uniquePaths(int m, int n) {
    //     vector<vector<int>> dp(m,vector<int>(n,-1));
    //     return solve(m-1,n-1,dp);
    // }


//appraoch 4: tabular dp bottom up

    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m,vector<int>(n,-1));
        
        for(int i = 0;i<m;i++){
            for(int j = 0;j<n;j++){
                if(i == 0 && j == 0){
                    dp[i][j] = 1;
                }
                else{
                    int count = 0;
                    //up if possible
                    if(i > 0){
                        count = count + dp[i-1][j];
                    }

                    //left
                    if(j > 0){
                        count = count + dp[i][j-1];
                    }

                    dp[i][j] = count;
                }

                
            }
        }

        return dp[m-1][n-1];
    }
};