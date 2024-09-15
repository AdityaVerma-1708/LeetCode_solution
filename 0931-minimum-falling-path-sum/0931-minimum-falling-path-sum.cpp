class Solution {
public: 

//approach 1: recurrsion 

    int solve(vector<vector<int>>& mat,int i,int j,int m,int n){
        if(i == m){
            return 0;
        }

        int minus = INT_MAX;
        int same = INT_MAX; 
        int plus = INT_MAX;

        if(j-1 >= 0){
            minus = min(minus,mat[i][j-1] + solve(mat,i+1,j-1,m,n));
        } 

        same = min(same,mat[i][j] + solve(mat,i+1,j,m,n));

        if(j+1 < n){
            plus = min(plus,mat[i][j+1] + solve(mat,i+1,j+1,m,n));
        }

        return min({minus,same,plus});
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

        for(int j = 0; j < n;j++){
            ans = min(ans,matrix[0][j] + solve(matrix,1,j,m,n));
        }
        
        return ans;
        
    }
};