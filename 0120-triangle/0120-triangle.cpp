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
    
    // int solve(vector<vector<int>>& triangle,int i,int j,int m,vector<vector<int>>&dp){
    //     if(i == m-1){
    //         return min(triangle[i][j],triangle[i][j+1]);
    //     }
    //     if(i == 0){
    //         return dp[i][j] = triangle[i][j] + solve(triangle,i+1,j,m,dp);
    //     }
    //     if(dp[i][j] != -1){
    //         return dp[i][j];
    //     }

    //     int ind = 0;
    //     int ind1 = 0;

    //     ind = triangle[i][j] + solve(triangle,i+1,j,m,dp);
    //     ind1 = triangle[i][j+1] + solve(triangle,i+1,j+1,m,dp);

    //     return dp[i][j] = min(ind,ind1);

    // }

    // int minimumTotal(vector<vector<int>>& triangle) {
    //     int m = triangle.size();
    //     int n = triangle[m-1].size();
    //     if(m == 1){
    //         return triangle[0][0];
    //     }
    //     vector<vector<int>> dp(m,vector<int>(n,-1));
    //     return solve(triangle,0,0,m,dp);
    // }


//approach 3: DP with tabular bottom up
    // int minimumTotal(vector<vector<int>>& triangle) {
    //     int n = triangle.size();
    //     vector<vector<int>> dp(n,vector<int>(n,-1));
    //     dp[0][0] = triangle[0][0];
        
    //     for(int i = 1;i<n;i++){
    //         for(int j = 0;j<triangle[i].size();j++){
    //             if(j == 0){
    //                 dp[i][j] = triangle[i][j] + dp[i-1][j];
    //             }
    //             else if(j == triangle[i].size()-1){
    //                 dp[i][j] = triangle[i][j] + dp[i-1][j-1];
    //             }
    //             else{
    //                 int up = triangle[i][j] + dp[i-1][j];
    //                 int left = triangle[i][j] + dp[i-1][j-1];
    //                 dp[i][j] = min(up,left);
    //             }
    //         }
    //     }
    //     int ans = INT_MAX;
    //     for(int i = 0;i<n;i++){
    //         ans = min(ans,dp[n-1][i]);
    //     }
    //     return ans;
    // } 

//approach 4: tabular dp space optimization    
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<int> prev(1,-1);
        prev[0] = triangle[0][0];
        
        for(int i = 1;i<n;i++){
            vector<int>temp(triangle[i].size(),-1);

            for(int j = 0;j<triangle[i].size();j++){
                if(j == 0){
                    temp[j] = triangle[i][j] + prev[j];
                }
                else if(j == triangle[i].size()-1){
                    temp[j] = triangle[i][j] + prev[j-1];
                }
                else{
                    int up = triangle[i][j] + prev[j];
                    int left = triangle[i][j] + prev[j-1];
                    temp[j] = min(up,left);
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