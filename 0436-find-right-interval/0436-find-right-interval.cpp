class Solution {
public:
    vector<int> findRightInterval(vector<vector<int>>& intervals) {
    //brute force:
        vector<int> ans(intervals.size(),-1);
        for(int i = 0;i<intervals.size();i++){
            for(int j = 0;j<intervals.size();j++){
                if(intervals[i][1] <= intervals[j][0]){
                    if(ans[i] != -1 && intervals[ans[i]][0] > intervals[j][0]){
                        ans[i] = j;
                    }
                    else if(ans[i] == -1){
                        ans[i] = j;
                    }
                }
            }
        }   
        return ans;
    }
};