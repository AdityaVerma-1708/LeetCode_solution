class Solution {
public:
    int longestPalindrome(string s) {
        int ans = 0;
        set<char> set;
        for(int i = 0;i<s.size();i++){
            auto it = set.find(s[i]);
            if(it == set.end()){
                set.insert(s[i]);
            }
            else{
                set.erase(it);
                ans = ans + 2;
            }
        }

        if(!set.empty()){
            ans = ans + 1;
        }
        return ans;
    }
};