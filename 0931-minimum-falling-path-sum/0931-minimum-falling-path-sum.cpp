class Solution {
public: 

//approach 1: recurrsion TLE@ 38/52
    // int solve(vector<vector<int>>& mat,int i,int j,int m,int n){
    //     if(i == m){
    //         return 0;
    //     }

    //     int minus = INT_MAX;
    //     int same = INT_MAX; 
    //     int plus = INT_MAX;

    //     if(j-1 >= 0){
    //         minus = min(minus,mat[i][j-1] + solve(mat,i+1,j-1,m,n));
    //     } 

    //     same = min(same,mat[i][j] + solve(mat,i+1,j,m,n));

    //     if(j+1 < n){
    //         plus = min(plus,mat[i][j+1] + solve(mat,i+1,j+1,m,n));
    //     }

    //     return min({minus,same,plus});
    // }

    // int minFallingPathSum(vector<vector<int>>& matrix) {
    //     int m = matrix.size();
    //     int n = matrix[0].size();

    //     int ans = INT_MAX;

    //     if(m == 1){
    //         for(int j = 0;j < n;j++){
    //             ans = min(ans,matrix[0][j]);
    //         }
    //         return ans;
    //     }

    //     for(int j = 0; j < n;j++){
    //         ans = min(ans,matrix[0][j] + solve(matrix,1,j,m,n));
    //     }
        
    //     return ans;   
    // }

//approach 2:

    int solve(vector<vector<int>>& mat,int i,int j,int m,int n,vector<vector<int>>&dp){
        if(i == m){
            return 0;
        }

        int minus = INT_MAX;
        int same = INT_MAX; 
        int plus = INT_MAX;

        if(dp[i][j] != INT_MAX){
            return dp[i][j];
        }

        if(j-1 >= 0){
            minus = min(minus,mat[i][j-1] + solve(mat,i+1,j-1,m,n,dp));
        } 

        same = min(same,mat[i][j] + solve(mat,i+1,j,m,n,dp));

        if(j+1 < n){
            plus = min(plus,mat[i][j+1] + solve(mat,i+1,j+1,m,n,dp));
        }

        return dp[i][j] = min({minus,same,plus});
    }

    int minFallingPathSum(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();

        int ans = INT_MAX;

        if(m == 1){
            for(int j = 0;j < n;j++){
                ans = min(ans,matrix[0][j]);
            }
            return ans;
        }
        vector<vector<int>>dp(m,vector<int>(n,INT_MAX));

        for(int j = 0; j < n;j++){
            dp[0][j] = min(dp[0][j],matrix[0][j] + solve(matrix,1,j,m,n,dp));
            ans = min(ans,dp[0][j]);
        }
        
        return ans;   
    }
};