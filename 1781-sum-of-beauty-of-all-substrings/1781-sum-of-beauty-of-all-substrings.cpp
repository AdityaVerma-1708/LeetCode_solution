class Solution {
public:
    int maxi(vector<int> count){
        int maxi = INT_MIN;
        for(int i = 0;i<count.size();i++){
            maxi = max(maxi,count[i]);
        }
        return maxi;
    }
    int mini(vector<int> count){
        int mini = INT_MAX;
        for(int i = 0;i<count.size();i++){
            if(count[i] < mini && count[i] > 0){
                mini = count[i];
            }
        }
        return mini;
    }

    int beautySum(string s) {
    //brute force:
        int ans = 0;
        for(int i = 0;i<s.size();i++){
            vector<int> count(26,0);
            for(int j = i;j<s.size();j++){
                count[s[j] - 'a']++;
                ans = ans + maxi(count) - mini(count);
            }
        }
        return ans;
    }
};