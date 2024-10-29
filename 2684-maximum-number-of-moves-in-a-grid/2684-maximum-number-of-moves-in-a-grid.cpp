class Solution {
public:
//approach 1: using recurrsion  TLE @810/814

    // int solve(vector<vector<int>>&grid,int i,int j,int num){
    //     if(j + 1 >= grid[0].size()){  //base case
    //         return num;
    //     }

    //     int curr = grid[i][j];

    //     int above;
    //     int same;
    //     int down;
        
    //     int ans = INT_MIN;

    //     //above
    //     if(i - 1 >= 0){
    //         if(grid[i-1][j+1] > curr){
    //             ans = max(ans,solve(grid,i-1,j+1,num+1));
    //         }
    //     }

    //     //same
    //     if(grid[i][j+1] > curr){
    //         ans = max(ans,solve(grid,i,j+1,num+1));
    //     }

    //     //down
    //     if(i + 1 < grid.size()){
    //         if(grid[i+1][j+1] > curr){
    //             ans = max(ans,solve(grid,i+1,j+1,num+1));
    //         }
    //     }
    //     return max(ans,num);
    // }

    // int maxMoves(vector<vector<int>>& grid) {
    //     int m = grid.size();  //row
    //     int n = grid[0].size(); //col
    //     int ans = 0;
    //     for(int i = 0;i<m;i++){
    //         ans = max(ans,solve(grid,i,0,0));
    //     }
    //     return ans;
    // }

//approach 2 : memoization

    int solve(vector<vector<int>>&grid,int i,int j,int num,vector<vector<int>>&dp){
        if(j + 1 >= grid[0].size()){  //base case
            return num;
        }

        if(dp[i][j] != -1){
            return dp[i][j];
        }

        int curr = grid[i][j];

        int above;
        int same;
        int down;
        
        int ans = INT_MIN;

        //above
        if(i - 1 >= 0){
            if(grid[i-1][j+1] > curr){
                ans = max(ans,solve(grid,i-1,j+1,num+1,dp));
            }
        }

        //same
        if(grid[i][j+1] > curr){
            ans = max(ans,solve(grid,i,j+1,num+1,dp));
        }

        //down
        if(i + 1 < grid.size()){
            if(grid[i+1][j+1] > curr){
                ans = max(ans,solve(grid,i+1,j+1,num+1,dp));
            }
        }
        return dp[i][j] = max(ans,num);
    }

    int maxMoves(vector<vector<int>>& grid) {
        int m = grid.size();  //row
        int n = grid[0].size(); //col
        int ans = 0;

        vector<vector<int>> dp(m,vector<int>(n,-1));

        for(int i = 0;i<m;i++){
            ans = max(ans,solve(grid,i,0,0,dp));
            dp[i][0] = max(ans,dp[i][0]);
        }
        return ans;
    }
};