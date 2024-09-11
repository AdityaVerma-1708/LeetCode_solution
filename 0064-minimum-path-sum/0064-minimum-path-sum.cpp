class Solution {
public:

//approach 1: recurssion

    int solve(vector<vector<int>>& grid,int i,int j,int m,int n){
        if(i == m-1 && j == n-1){
            return grid[i][j];
        }

        int down = INT_MAX;
        int right = INT_MAX;
        //down
        if(i+1 < m){
            down = min(grid[i][j] + solve(grid,i+1,j,m,n),down);
        }

        //right
        if(j+1 < n){
            right = min(grid[i][j] + solve(grid,i,j+1,m,n),right);
        }

        return min(down,right);
    }

    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
    
        return solve(grid,0,0,m,n);
    }
};