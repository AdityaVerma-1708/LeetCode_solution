class Solution {
public:

    string reverseParentheses(string s) {
        if(s.size() == 1){
            return s;
        }
        else{
            stack<char> st;
            int i = 0; 
            while(i < s.size()){
                if(st.empty()){
                    st.push(s[i]);
                    i++;
                }
                else{
                    if(s[i] == '('){
                        st.push(s[i]);
                        i++;
                    }
                    else{
                        if(s[i] == ')'){
                            string temp = "";
                            while(st.top() != '('){
                                temp = temp + st.top();
                                st.pop();
                            }
                            st.pop();
                            int j = 0;
                            while(j<temp.size()){
                                st.push(temp[j]);
                                j++;
                            }
                            i++;
                        }
                        else{
                            st.push(s[i]);
                            i++;
                        }
                    }
                }
            }

            string ans = "";
            while(!st.empty()){
                ans = ans + st.top();
                st.pop();
            }
            reverse(ans.begin(),ans.end());
            return ans;
        }
    }
};