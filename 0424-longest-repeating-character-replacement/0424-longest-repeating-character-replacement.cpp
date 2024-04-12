class Solution {
public:
    int characterReplacement(string s, int k) {
    //brute force
        int ans = 0;
        for(int i = 0;i<s.size();i++){
            int map[26] = {0};
            int maxf = 0;
            for(int j = i;j<s.size();j++){
                map[s[j] - 'A']++;
                maxf = max(maxf,map[s[j] - 'A']);
                
                int changes = (j - i + 1) - maxf;
                if(changes <= k){
                    ans = max(ans,j-i+1);
                }
                else{
                    break;
                }
            }
        }
        return ans;
    }
};