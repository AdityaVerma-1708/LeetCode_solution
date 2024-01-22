class Solution {
public:
    int maxPower(string s) {
    //approach 1:   
        if(s.size()<2){
            return s.size();
        } 
        else{
            int i = 0;
            int j = 0;
            int ans = 0;
            int count = 0;

            while(j < s.size()){
                if(s[i] != s[j]){
                    ans = max(ans,count);
                    count = 0;
                    i++;
                }
                else{
                    count++;
                    j++;
                }
            }
            ans = max(ans,count);
            return ans;
        }
    }
};