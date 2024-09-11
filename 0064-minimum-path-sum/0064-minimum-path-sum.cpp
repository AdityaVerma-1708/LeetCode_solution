class Solution {
public:

//approach 1: recurssion TLE @25/66
    // int solve(vector<vector<int>>& grid,int i,int j,int m,int n){
    //     if(i == m-1 && j == n-1){
    //         return grid[i][j];
    //     }

    //     int down = INT_MAX;
    //     int right = INT_MAX;
    //     //down
    //     if(i+1 < m){
    //         down = min(grid[i][j] + solve(grid,i+1,j,m,n),down);
    //     }

    //     //right
    //     if(j+1 < n){
    //         right = min(grid[i][j] + solve(grid,i,j+1,m,n),right);
    //     }

    //     return min(down,right);
    // }

    // int minPathSum(vector<vector<int>>& grid) {
    //     int m = grid.size();
    //     int n = grid[0].size();
    
    //     return solve(grid,0,0,m,n);
    // }


//approach 2: DP memoization Bottom up

    // int solve(vector<vector<int>>& grid,int i,int j,int m,int n,vector<vector<int>>&dp){
    //     if(i == m-1 && j == n-1){
    //         return grid[i][j];
    //     }

    //     if(dp[i][j] != -1){
    //         return dp[i][j];
    //     }

    //     int down = INT_MAX;
    //     int right = INT_MAX;
    //     //down
    //     if(i+1 < m){
    //         down = min(grid[i][j] + solve(grid,i+1,j,m,n,dp),down);
    //     }

    //     //right
    //     if(j+1 < n){
    //         right = min(grid[i][j] + solve(grid,i,j+1,m,n,dp),right);
    //     }

    //     return dp[i][j] = min(down,right);
    // }

    // int minPathSum(vector<vector<int>>& grid) {
    //     int m = grid.size();
    //     int n = grid[0].size();

    //     vector<vector<int>>dp(m,vector<int>(n,-1));
    
    //     return solve(grid,0,0,m,n,dp);
    // }

//appraoch 3: dp memoization top down 

    // int solve(vector<vector<int>>&grid,int i,int j,vector<vector<int>>&dp){
    //     if(i == 0 && j == 0){
    //         return grid[i][j];
    //     }

    //     if(dp[i][j] != -1){
    //         return dp[i][j];
    //     }

    //     int up = INT_MAX;
    //     int left = INT_MAX;

    //     //up
    //     if(i-1 >= 0){
    //         up = min(up,grid[i][j] + solve(grid,i-1,j,dp));
    //     }

    //     //left
    //     if(j-1 >= 0){
    //         left = min(left,grid[i][j] + solve(grid,i,j-1,dp));
    //     }

    //     return dp[i][j] = min(up,left);
    // }

    // int minPathSum(vector<vector<int>>& grid) {
    //     int m = grid.size();
    //     int n = grid[0].size();

    //     vector<vector<int>>dp(m,vector<int>(n,-1));
    
    //     return solve(grid,m-1,n-1,dp);
    // }
    
//appraoch 4: dp tabular bottom up
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>>dp(m,vector<int>(n,-1));
    
        for(int i = 0;i<m;i++){
            for(int j = 0;j<n;j++){
                if(i == 0 && j == 0){
                    dp[i][j] = grid[i][j];
                }
                else{
                    int down = INT_MAX;
                    int right = INT_MAX;
                    if(i > 0){
                        down = min(down,grid[i][j] + dp[i-1][j]);
                    }
                    
                    if(j > 0){
                        right = min(right,grid[i][j] + dp[i][j-1]);
                    }
                    
                    dp[i][j] = min(down,right);
                }
            }
        }

        return dp[m-1][n-1];
    }    
};