class Solution {
public:
    string compressedString(string word) {
        string ans = "";
        int i = 0;
        int j = 0;
        
        while(j<word.size()){
            if(j - i == 9){
                stringstream ss;
                ss << j - i;
                ans += ss.str() + word[i];
                // ans = ans + to_string(j-i) + word[i];
                i = j;
            }
            else if(word[i] != word[j]){
                stringstream ss;
                ss << j - i;
                ans += ss.str() + word[i];
                // ans = ans + to_string(j-i) + word[i];
                i = j;
            }
            else{
                j++;
            }
        }
        stringstream ss;
        ss << j - i;
        ans += ss.str() + word[i];
        // ans = ans + to_string(j-i) + word[i];

        return ans;
    }
};