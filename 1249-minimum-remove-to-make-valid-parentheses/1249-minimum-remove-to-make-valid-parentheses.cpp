class Solution {
public:
    string minRemoveToMakeValid(string s) {
        int a = 0;
        for(int i = 0;i<s.size();i++){
            if(s[i] == '('){
                a = a + 1;
            }
            else if(s[i] == ')'){
                a = a - 1;
            }

            if(a < 0){
                s.erase(s.begin()+i);
                a = a + 1;
                i--;
            }
        }
        
        a = 0;
        for(int i = s.size()-1;i>=0;i--){
            if(s[i] == '('){
                a = a - 1;
            }
            else if(s[i] == ')'){
                a = a + 1;
            }

            if(a < 0){
                s.erase(s.begin()+i);
                a = a + 1;
            }
        }

        return s;
    }
};