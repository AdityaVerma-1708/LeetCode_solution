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

//approach 2: using dp memoization bottom up

    // int solve(vector<vector<int>>& mat,int i,int j,int m,int n,vector<vector<int>>&dp){
    //     if(i == m){
    //         return 0;
    //     }

    //     int minus = INT_MAX;
    //     int same = INT_MAX; 
    //     int plus = INT_MAX;

    //     if(dp[i][j] != INT_MAX){
    //         return dp[i][j];
    //     }

    //     if(j-1 >= 0){
    //         minus = min(minus,mat[i][j-1] + solve(mat,i+1,j-1,m,n,dp));
    //     } 

    //     same = min(same,mat[i][j] + solve(mat,i+1,j,m,n,dp));

    //     if(j+1 < n){
    //         plus = min(plus,mat[i][j+1] + solve(mat,i+1,j+1,m,n,dp));
    //     }

    //     return dp[i][j] = min({minus,same,plus});
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
    //     vector<vector<int>>dp(m,vector<int>(n,INT_MAX));

    //     for(int j = 0; j < n;j++){
    //         dp[0][j] = min(dp[0][j],matrix[0][j] + solve(matrix,1,j,m,n,dp));
    //         ans = min(ans,dp[0][j]);
    //     }
        
    //     return ans;   
    // }

//approach 3: tabular dp bottom up

    // int minFallingPathSum(vector<vector<int>>& matrix) {
    //     int m = matrix.size();
    //     int n = matrix[0].size();

    //     vector<vector<int>>dp(m,vector<int>(n,INT_MAX));
    //     for(int i = 0;i<m;i++){
    //         for(int j = 0;j<n;j++){
    //             if(i == 0){
    //                 dp[i][j] = matrix[i][j];
    //             }
    //             else{
    //                 if(j == 0 && j == n-1){
    //                     //only up
    //                     dp[i][j] = matrix[i][j] + dp[i-1][j];
    //                 }
    //                 else if(j == n-1){
    //                     //up and left
    //                     int up = matrix[i][j] + dp[i-1][j];
    //                     int left = matrix[i][j] + dp[i-1][j-1];

    //                     dp[i][j] = min(up,left);
    //                 }
    //                 else if(j == 0){
    //                     //up and right
    //                     int up = matrix[i][j] + dp[i-1][j];
    //                     int right = matrix[i][j] + dp[i-1][j+1];

    //                     dp[i][j] = min(up,right);
    //                 }
    //                 else{
    //                     int up = matrix[i][j] + dp[i-1][j];
    //                     int left = matrix[i][j] + dp[i-1][j-1];
    //                     int right = matrix[i][j] + dp[i-1][j+1];

    //                     dp[i][j] = min({up,left,right});
    //                 }
    //             }
    //         }
    //     }

    //     int ans = INT_MAX;
    //     for(int i = 0;i<n;i++){
    //         ans = min(ans,dp[m-1][i]);
    //     }  
    //     return ans;
    // }


//approach 3: tabular dp space optimization

    int minFallingPathSum(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();

        vector<int>prev(n,INT_MAX);
        for(int i = 0;i<m;i++){
            vector<int>temp(n,-1);
            for(int j = 0;j<n;j++){
                if(i == 0){
                    temp[j] = matrix[i][j];
                }
                else{
                    if(j == 0 && j == n-1){
                        //only up
                        temp[j] = matrix[i][j] + prev[j];
                    }
                    else if(j == n-1){
                        //up and left
                        int up = matrix[i][j] + prev[j];
                        int left = matrix[i][j] + prev[j-1];

                        temp[j] = min(up,left);
                    }
                    else if(j == 0){
                        //up and right
                        int up = matrix[i][j] + prev[j];
                        int right = matrix[i][j] + prev[j+1];

                        temp[j] = min(up,right);
                    }
                    else{
                        int up = matrix[i][j] + prev[j];
                        int left = matrix[i][j] + prev[j-1];
                        int right = matrix[i][j] + prev[j+1];

                        temp[j] = min({up,left,right});
                    }
                }
            }
            prev = temp;
        }

        int ans = INT_MAX;
        for(int i = 0;i<n;i++){
            ans = min(ans,prev[i]);
        }  
        return ans;
    }
};