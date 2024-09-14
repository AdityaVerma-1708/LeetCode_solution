class Solution {
public:
//approach 1: recurrsion

    // int solve(vector<vector<int>>& triangle,int i,int j,int m){
    //     if(i == m-1){
    //         return min(triangle[i][j],triangle[i][j+1]);
    //     }
    //     if(i == 0){
    //         return triangle[i][j] + solve(triangle,i+1,j,m);
    //     }

    //     int ind = 0;
    //     int ind1 = 0;

    //     ind = triangle[i][j] + solve(triangle,i+1,j,m);
    //     ind1 = triangle[i][j+1] + solve(triangle,i+1,j+1,m);

    //     return min(ind,ind1);

    // }

    // int minimumTotal(vector<vector<int>>& triangle) {
    //     int m = triangle.size();
    //     if(m == 1){
    //         return triangle[0][0];
    //     }
    //     return solve(triangle,0,0,m);
    // }

//approach 2: DP with memoization bottom up
    
    int solve(vector<vector<int>>& triangle,int i,int j,int m,vector<vector<int>>&dp){
        if(i == m-1){
            return min(triangle[i][j],triangle[i][j+1]);
        }
        if(i == 0){
            return dp[i][j] = triangle[i][j] + solve(triangle,i+1,j,m,dp);
        }
        if(dp[i][j] != -1){
            return dp[i][j];
        }

        int ind = 0;
        int ind1 = 0;

        ind = triangle[i][j] + solve(triangle,i+1,j,m,dp);
        ind1 = triangle[i][j+1] + solve(triangle,i+1,j+1,m,dp);

        return dp[i][j] = min(ind,ind1);

    }

    int minimumTotal(vector<vector<int>>& triangle) {
        int m = triangle.size();
        if(m == 1){
            return triangle[0][0];
        }
        vector<vector<int>> dp(m,vector<int>(m,-1));
        return solve(triangle,0,0,m,dp);
    }
};