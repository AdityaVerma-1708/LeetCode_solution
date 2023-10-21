class Solution {
public:
    int compress(vector<char>& chars) {
        string ans;
        int i=0;
        while(i<chars.size()){
            int j = i+1;
            int count=1;
            while(j<chars.size() && chars[i] == chars[j]){
                j++;
                count++;
            }
            ans.push_back(chars[i]);
            if(count > 1){
                string a = to_string(count);
                for(auto ch : a){
                    ans.push_back(ch);
                }
            }
            i = j;
            j = 1;
        }
        chars.clear();

        for(auto val : ans){
            chars.push_back(val);
        }
        return chars.size();
    }
};