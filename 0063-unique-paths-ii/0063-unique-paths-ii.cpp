class Solution {
public:

//approach 1: recurrsion TLE

    // int solve(vector<vector<int>>& mat,int i,int j,int m,int n){
    //     if(i == m-1 && j == n-1){
    //         return 1;
    //     }

    //     if(mat[i][j] == 1){
    //         return 0;
    //     }

    //     int count = 0;
    //     //go right
    //     if(j+1 < n){
    //         count = count + solve(mat,i,j+1,m,n);
    //     }

    //     //go down
    //     if(i+1 < m){
    //         count = count + solve(mat,i+1,j,m,n);
    //     }

    //     return count;
    // }

    // int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
    //     int m = obstacleGrid.size();
    //     int n = obstacleGrid[0].size();
        
    //     if(obstacleGrid[m-1][n-1] == 1){
    //         return 0;
    //     }

    //     return solve(obstacleGrid,0,0,m,n);
    // }

//appraoch 2: dp with memoization bottom up

    int solve(vector<vector<int>>& mat,int i,int j,int m,int n,vector<vector<int>>&dp){
        if(i == m-1 && j == n-1){
            return 1;
        }

        if(dp[i][j] != -1){
            return dp[i][j];
        }

        if(mat[i][j] == 1){
            return dp[i][j] = 0;
        }

        int count = 0;
        //go right
        if(j+1 < n){
            count = count + solve(mat,i,j+1,m,n);
        }

        //go down
        if(i+1 < m){
            count = count + solve(mat,i+1,j,m,n);
        }

        return dp[i][j] = count;
    }

    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        
        if(obstacleGrid[m-1][n-1] == 1){
            return 0;
        }

        vector<vector<int>>dp(m,vector<int>(n,-1));
        return solve(obstacleGrid,0,0,m,n,dp);
    }
};