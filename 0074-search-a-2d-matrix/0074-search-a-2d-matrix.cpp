class Solution {
public:


    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();

        int i=0,j; 
        if(m > 1){     //if only one row is there we dont need to find the row  
            for(int k=0;k<m;k++){
                if(target == matrix[k][n-1]){
                    return true;
                }
                else if(target < matrix[k][n-1]){
                    i = k;
                    break;
                }
            }
        }
        
        //if only one col is there we dont need to apply binary search
        if(n > 1){
            int s = 0;
            int e = n-1;

            while(s<=e){
                int mid = (s+e)/2;
                if(matrix[i][mid] == target){
                    return true;
                }
                else if(matrix[i][mid] < target){
                    s = mid+1;
                }
                else{
                    e = mid-1;
                }
            }
            return false;
        }
        
        if(matrix[i][n-1] == target){
            return true;
        }    
        return false;
    }
};