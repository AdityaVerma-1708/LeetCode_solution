class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
    // approch 1:

        // int m = matrix.size();
        // int n = matrix[0].size();
        // unordered_set<int> row;
        // unordered_set<int> col;

        // for(int i=0;i<m;i++){
        //     for(int j=0;j<n;j++){
        //         if(matrix[i][j] == 0){
        //             row.insert(i);
        //             col.insert(j);
        //         }
        //     }
        // }

        // for(int i=0;i<m;i++){
        //     for(int j=0;j<n;j++){
        //         if(row.count(i) || col.count(j)){
        //             matrix[i][j] = 0;
        //         }
        //     }
        // }

        
    //approch 2: using for loop and using space
        int row = matrix.size();
        int col = matrix[0].size();

        vector<vector<int>> temp = matrix;

        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(matrix[i][j] == 0){
                    for(int k=0;k<row;k++){
                        temp[k][j] = 0;
                    }
                    for(int k=0;k<col;k++){
                        temp[i][k] = 0;
                    }
                }
            }
        }

        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                matrix[i][j] = temp[i][j];
            }
        }

    }
};