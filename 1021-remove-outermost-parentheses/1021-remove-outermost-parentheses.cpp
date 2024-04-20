class Solution {
public:
    string removeOuterParentheses(string s) {
    //brute force:
        stack<char> stack;
        string ans = "";
        for(int i = 0;i<s.size();i++){
            if(s[i] == '('){
                if(!stack.empty()){
                    ans.push_back(s[i]);
                }
                stack.push(s[i]);
            }
            else{
                stack.pop();
                if(!stack.empty()){  // not the outer one 
                    ans.push_back(')');
                }
            }
        }
        return ans;
    }
};