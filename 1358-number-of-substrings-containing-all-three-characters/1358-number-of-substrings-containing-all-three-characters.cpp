class Solution {
public:
    int numberOfSubstrings(string s) {
    //brute force:
        int i = 0;
        int j = 0;
        int ans = 0; 
        unordered_map<char,int> map;

        while(j < s.size()){
            map[s[j]]++;

            if(map.size() == 3){
                ans = ans + s.size() - j;

                while(map.size() == 3){
                    map[s[i]]--;

                    if(map[s[i]] == 0){
                        map.erase(s[i]);
                    }

                    i++;

                    if(map.size() == 3){
                        ans = ans + s.size() - j;
                    }

                }

            }
            j++;
        }   

        return ans;
    }
};