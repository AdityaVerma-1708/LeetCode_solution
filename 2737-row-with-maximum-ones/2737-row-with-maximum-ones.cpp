class Solution {
public:
    vector<int> rowAndMaximumOnes(vector<vector<int>>& mat) {
        int maxi = 0;
        int m = mat.size();
        int n = mat[0].size();
        int index = 0;
        for(int i=0;i<m;i++){
            int count = 0;
            for(int j=0;j<n;j++){
                if(mat[i][j] == 1){
                    count++;
                }
            }
            if(count > maxi){
                index = i;
            }
            maxi = max(maxi,count);
        }
        return {index,maxi};
    }
};