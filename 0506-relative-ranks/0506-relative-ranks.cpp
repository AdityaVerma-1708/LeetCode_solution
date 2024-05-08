class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
    //brute force:    
        vector<string> ans(score.size());
        vector<int> temp = score;
        sort(temp.rbegin(),temp.rend());

        for(int i = 0;i< score.size();i++){
            for(int j = 0;j< temp.size();j++){
                if(score[i] == temp[j]){
                    if(j+1 == 1){
                        ans[i] = "Gold Medal";
                    }
                    else if (j+1 == 2){
                        ans[i] = "Silver Medal";
                    }
                    else if (j+1 == 3){
                        ans[i] = "Bronze Medal";
                    }
                    else{
                        ans[i] = to_string(j+1);
                    }
                } 
            }
        }

        return ans;
    }
};