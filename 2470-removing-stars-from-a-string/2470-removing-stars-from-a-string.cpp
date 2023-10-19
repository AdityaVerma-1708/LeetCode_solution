class Solution {
public:
    string removeStars(string s) {
    //approch 1: taking 101ms time \U0001f62c     
        string ans;
        for(int i=0;i<s.size();i++){
            if(s[i] == '*'){
                if(ans.size()==0){
                    continue;
                }
                else{
                    ans.pop_back();
                }
            }
            else{
                ans.push_back(s[i]);
            }
        }
        return ans;

    

    }
};