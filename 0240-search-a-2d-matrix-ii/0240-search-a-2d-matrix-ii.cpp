class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row = matrix.size();
        int col = matrix[0].size();

        vector<int> targetrows;

        //if only one row is there we dont need to search for target rows
        if(row > 1){
            for(int k = 0; k < row; k++){
                if(target <= matrix[k][col-1] && target >= matrix[k][0]){
                    targetrows.push_back(k);
                }
            }
        }

        //if only one col is there we dont need to apply binary search
        if(col > 1){
            //binary search in all targeted rows

            //if no. of rows is 1, then we didnt push anything in the vector
            if(targetrows.empty()){
                targetrows.push_back(0);
            }
            for(auto val : targetrows){
                int s = 0,e = col-1; 
                while(s <= e){
                    int mid = (s+e)/2;
                    if(matrix[val][mid] == target){
                        return true;
                    }
                    else if(matrix[val][mid] > target){
                        e = mid - 1;
                    }
                    else{
                        s = mid + 1;
                    }
                }
            }  
        }

        /* we have these cases:
            - when row is 1 and col is more (search on that single row only)
            - when row and col both > 1 (general case)
            we have to consider the case
            - when col is 1 and row > 1
        */

        if(targetrows.empty()){ // row = col = 1
            if(matrix[row-1][col-1] == target){
            return true;
        }
            else{
                return false;
            }
        }
        else{ //row > 1 and col = 1
            for(auto val : targetrows){
                if(matrix[val][col-1] == target){
                    return true;
                }
            }
        }
        return false;
        
    }
};