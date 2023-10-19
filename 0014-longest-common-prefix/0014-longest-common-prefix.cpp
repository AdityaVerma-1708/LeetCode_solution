class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string ans = "";
        int flag = 0;
        for(int i=0;i<strs[0].length();i++){
            char ch = strs[0][i];
            for(int j=1;j<strs.size();j++){
                if(ch != strs[j][i]){
                    // return "";
                    flag = 1;
                    break;
                }
                // else{
                //     ans.push_back(ch);
                // }
            }
            if(flag == 1){
                break;
            }
            else{
                    ans.push_back(ch);
            }
        }
        return ans;  
    }
    
};