class Solution {
public:
    bool isIsomorphic(string s, string t) {
        // map<char,char> map;
        // for(int i=0;i<s.size();i++){
        //     if(map[s[i]] != 0){
        //         if(map[s[i]] != t[i]){
        //             return false;
        //         }
        //     }
        //     else{
        //         map[s[i]] = t[i];
        //     }
        // }
        // return true;
        //--requires modification

//approch 1
        // unordered_set<char> s1,s2;
        // for(auto val : s){
        //     s1.insert(val);
        // }
        // for(auto val : t){
        //     s2.insert(val);
        // }
        // if(s1.size() != s2.size()){
        //     return false;
        // }
        // else{
        //     map<char,char> map;
        //     for(int i=0;i<s.size();i++){
        //         if(map[s[i]] != 0){
        //             if(map[s[i]] != t[i]){
        //                 return false;
        //             }
        //         }
        //         else{
        //             map[s[i]] = t[i];
        //         }
        //     }
        //     return true;
        // }

    //here we have used two sets and 1 map

//approch 2 - can use 2 maps;
        unordered_map<char,char> map1,map2;
        for(int i=0;i<s.size();i++){
            if(map1[s[i]] != 0 && map1[s[i]] != t[i]){
                return false;
            }
            if(map2[t[i]] != 0 && map2[t[i]] != s[i]){
                return false;
            }
            map1[s[i]] = t[i];
            map2[t[i]] = s[i];
        }
        return true;
    }
};