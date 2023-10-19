class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
        string ans;
        int i = 0;
        int j = 0;
        int k = 0;
        int n = s.size() + spaces.size();
        while(i < n){
            if(k < spaces.size() && j == spaces[k]){
                k++;
                ans.push_back(' ');
            }
            else{
                ans.push_back(s[j]);
                j++;
            }
            i++;
        }
        return ans;

        //we can do optimizaton of space with reducing number of variable 
    }
};