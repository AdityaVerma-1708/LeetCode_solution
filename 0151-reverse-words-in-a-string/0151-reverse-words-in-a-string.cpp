class Solution {
public:
    string reverseWords(string s) {
    //approch 1: brute force  TLE
        // string ans = "";
        // int i = s.size()-1;
        // int j = i;

        // while (i >= 0 && s[i] == ' ') {
        //     i--;
        //     j--;
        // }

        // while(j>=0 && j<=i){
        //     if(isalnum(s[i]) == 0 && isalnum(s[j]) == 0){
        //         i--;
        //         j--;
        //     }
        //     else if(isalnum(s[i]) == 1 && isalnum(s[j]) == 1){
        //         j--;
        //     }
        //     else if(isalnum(s[i]) == 1 && isalnum(s[j]) == 0){
        //         for(int k = j+1;k<=i;k++){
        //             ans.push_back(s[k]);
        //         }
        //         ans.push_back(' ');
        //         i = j;
        //     }
        // }
        // return ans;

    //approach 2: using stack
        stack<string> stack;
        for(int i = 0;i<s.size();i++){
            if(s[i] == ' '){
                while(s[i] == ' ' && i < s.size()){
                    i++;
                }
                i--;
            }
            else{
                string words="";
                while(s[i] != ' ' && i < s.size()){
                    words = words + s[i];
                    i++;
                }
                stack.push(words);
                stack.push(" ");
            }
        }

        string ans = "";
        stack.pop();
        while(stack.empty() == 0){
            ans = ans + stack.top();
            stack.pop();
        }
        return ans;  
    }
};