class Solution {
public:
    int longestContinuousSubstring(string s) {
    //appraoch 1:
        if(s.size() < 2){
            return s.size();
        }
        else{
            int ans = 1;
            int i = 0;
            int j = 1;
            int count = 1;
            while(j < s.size()){
                if( int(s[j]) - int(s[j-1]) == 1){
                    count++;
                    j++;
                }
                else{
                    ans = max(ans,count);
                    count = 1;
                    i = j;
                    j++;
                }
            }
            ans = max(ans,count);
            return ans;
        }

    }
};