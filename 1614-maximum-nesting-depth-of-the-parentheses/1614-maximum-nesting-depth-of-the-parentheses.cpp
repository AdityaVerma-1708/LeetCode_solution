class Solution {
public:
    int maxDepth(string s) {
    //brute force
        int count = 0;
        int ans = 0;
        stack<char> stack;
        for(int i = 0;i<s.size();i++){
            if(s[i] == '(' || s[i] == ')'){
                if(stack.empty()){
                    stack.push(s[i]);
                    count++;
                    ans = max(ans,count);
                }
                else{
                    if(s[i] == '('){
                        stack.push(s[i]);
                        count++;
                        ans = max(ans,count);
                    }
                    else{
                        stack.pop();
                        count--;
                        ans = max(ans,count);
                    }
                }
            }
        }
        return ans;
    }
};