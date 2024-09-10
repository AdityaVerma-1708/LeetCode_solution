class Solution {
public:

//appraoch 1: recurrsion 
    int solve(int i,int j,int m,int n){
        if(i == m-1 && j == n-1){
            return 1;
        }

        int count = 0;
        //right if possible
        if(j+1 < n){
            count = count + solve(i,j+1,m,n);
        }

        //down if possible
        if(i+1 < m){
            count = count + solve(i+1,j,m,n);
        }

        return count;
    }

    int uniquePaths(int m, int n) {
        return solve(0,0,m,n);
    }
};