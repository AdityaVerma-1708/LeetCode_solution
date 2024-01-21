class Solution {
public:
    int countGoodSubstrings(string s) {
    //appraoch 1 : since it specifies the size of the window i.e three hence its a simple
        if(s.size() < 3){
            return 0;
        }
        else{
            int i = 0;
            int j = 2;
            int count = 0;
            while(j < s.size()){
                if(s[i] == s[i+1] || s[i] == s[j] || s[i+1] == s[j]){
                    i++;
                    j++;
                    continue;
                }
                else{
                    count++;
                    i++;
                    j++;
                }
                
            }
            return count;
        }
    }
};