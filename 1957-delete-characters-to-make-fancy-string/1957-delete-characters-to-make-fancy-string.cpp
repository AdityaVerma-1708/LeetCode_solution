class Solution {
public:

//approach 1 : MLE 
    // string makeFancyString(string s) {
    //     if(s.size() < 3){
    //         return s;
    //     }
    //     else{
    //         int i = 0;
    //         int j = 2;
    //         string ans = "";
    //         while(j < s.size()-1){
    //             if(s[i] != s[j]){
    //                 ans = ans + s[i];
    //                 i++;
    //                 j++;
    //             }
    //             else{ // s[i] == s[j]
    //                 if(s[i] == s[i+1]){  // all three are equal
    //                     i++;
    //                     j++;
    //                 } 
    //                 else{
    //                     ans = ans + s[i];
    //                     i++;
    //                     j++;
    //                 }
    //             }
    //         }

    //         //last window
    //         if(s[i] != s[j]){
    //             ans = ans + s[i] + s[i+1] + s[i+2];
    //         }
    //         else{ // s[i] == s[j]
    //             if(s[i] == s[i+1]){  // all three are equal
    //                 ans = ans + s[i+1] + s[i+2];
    //             } 
    //             else{
    //                 ans = ans + s[i] + s[i+1] + s[i+2];
    //             }
    //         }
    //         return ans;
    //     }
    // }

//approach 2:

    string makeFancyString(string s) {
        if(s.size() < 3){
            return s;
        }
        else{
            string ans = "";
            for (char c : s) {
                int n = ans.size();
                // Append current character only if last two characters are not the same as this character
                if (n < 2 || !(ans[n - 1] == c && ans[n - 2] == c)) {
                    ans += c;
                }
            }
            return ans;
        }
    }
};