class Solution {
public:

    int maxelement(vector<vector<int>>& mat,int mid){
        int maxi = -1;
        int index = -1;

        for(int i = 0;i<mat.size();i++){
            if(mat[mid][i] > maxi){
                maxi = mat[i][mid];
                index = i;
            }
        }

        return index;
    }

    vector<int> findPeakGrid(vector<vector<int>>& mat) {
    //brute force:  
        int m = mat.size();
        int n = mat[0].size();

        int i = 0;
        int j = n - 1;

        while(i<=j){
            int mid = (i+j)/2;
            int row = maxelement(mat,mid);

            int left = -1;
            int right = -1;
            if(mid - 1 >= 0){
                left = mat[row][mid-1];
            }
            if(mid + 1 < n){
                right = mat[row][mid+1];
            }

            if(mat[row][mid] > left && mat[row][mid] > right){
                return {row,mid};
            }
            else if(mat[row][mid] < left){
                j = mid - 1;
            }
            else{
                i = mid + 1;
            }
        }
        return {-1,-1};
        
    }
};