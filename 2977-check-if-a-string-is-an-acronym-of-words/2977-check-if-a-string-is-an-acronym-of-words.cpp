class Solution {
public:
    bool isAcronym(vector<string>& words, string s) {
    //approch 1:
        if(words.size() != s.size()){
            return false;
        }
        else{
            int i = 0 ;
            for(auto val : words){
                if(val[0] != s[i] || i==s.size()){
                    return false;
                }
                i++;
            }
            return true;
        }
    }
};