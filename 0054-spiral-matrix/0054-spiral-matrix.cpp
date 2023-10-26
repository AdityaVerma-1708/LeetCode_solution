class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
    //approch 1: my first, not completed     
        // vector<int> ans;
        // int m = matrix.size();
        // int n = matrix[0].size();
        // int count = m*n;
        // int i = 0 , j = 0;
        // while(count != 0){
        //     if(i == j || ){ //move right
        //         while(j<m){
        //             ans.push_back(matrix[i][j]);
        //             j++;
        //             count--;
        //         }
        //     }
        //     else if(j > i){ //move down
        //         while(i<n){
        //             ans.push_back(matrix[i][j]);
        //             i++;
        //             count--;
        //         }
        //     }
        //     else if(i > j){  //move up
        //         while()
        //     }
        // }

    //appproch 2:
        vector<int> ans;
        int row = matrix.size();
        int col = matrix[0].size();

        int count = row*col;

        int startingrow = 0;
        int startingcol = 0;
        int endingrow = row-1;
        int endingcol = col-1;

        while(count!=0){

            for(int i = startingcol; count!=0 && i <= endingcol; i++){
                ans.push_back(matrix[startingrow][i]);
                count--;
            }
            startingrow++;

            for(int i = startingrow; count!=0 && i <= endingrow; i++){
                ans.push_back(matrix[i][endingcol]);
                count--;
            }
            endingcol--;

            for(int i = endingcol; count!=0 && i >= startingcol; i--){
                ans.push_back(matrix[endingrow][i]);
                count--;
            }
            endingrow--;

            for(int i = endingrow; count!=0 && i >= startingrow; i--){
                ans.push_back(matrix[i][startingcol]);
                count--;
            }
            startingcol++;

        }
        return ans;
    }
};