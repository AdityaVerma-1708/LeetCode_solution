class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
    // approch 1:
        int m = matrix.size();
        int n = matrix[0].size();
        unordered_set<int> row;
        unordered_set<int> col;

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(matrix[i][j] == 0){
                    row.insert(i);
                    col.insert(j);
                }
            }
        }

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(row.count(i) || col.count(j)){
                    matrix[i][j] = 0;
                }
            }
        }
    //approch 2:

    }
};