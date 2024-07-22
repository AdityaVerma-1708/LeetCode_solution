class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
    //approach 1: using two for loops
    //appraoch 2 : optimization
        int ans = 0;
        for(int i = 0;i<grid.size();i++){
            int j = 0;
            int k = grid[0].size()-1;
            int index = -1;
            while(j<=k){
                int mid = (j+k)/2;
                if(grid[i][mid] < 0){
                    index = mid;
                    k = mid - 1;
                }
                else{
                    j = mid + 1;
                }
            }
            if(index != -1){    
                ans = ans + grid[0].size() - index;
            }
        }   
        return ans;
    }
};