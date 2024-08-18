class Solution {
public:
    int numberOfSubstrings(string s) {
    //brute force:
        int i = 0;
        int j = 0;
        int ans1 = 0; 
        unordered_map<char,int> map;
        while(j < s.size()){
            map[s[j]]++;
            if(map.size() == 3){
                ans1 = ans1 + s.size() - j;
                while(map.size() == 3){
                    map[s[i]]--;
                    if(map[s[i]] == 0){
                        map.erase(s[i]);
                    }
                    i++;
                    if(map.size() == 3){
                        ans1 = ans1 + s.size() - j;
                    }
                }
            }
            j++;
        }   

        // j = s.size()-1;
        // i = s.size()-1;
        // int ans2 = 0;
        // map.clear();
        // while(j > 0){
        //     map[s[j]]++;
        //     if(map.size() == 3){
        //         ans2 = ans2 + j + 1;
        //         while(map.size() == 3){
        //             map[s[i]]--;
        //             if(map[s[i]] == 0){
        //                 map.erase(s[i]);
        //             }
        //             i--;
        //         }
        //     }
        //     j--;
        // }

        // return max(ans1,ans2);
        return ans1;
    }
};