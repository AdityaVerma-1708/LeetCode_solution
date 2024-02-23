class Solution {
public:
//approch 1: TLE for large input
    // bool check_anagram(string s , string t){
    //     sort(s.begin(),s.end());
    //     sort(t.begin(),t.end());
    //     if(s==t){
    //         return true;
    //     }
    //     else{
    //         return false;
    //     }
    // }
    // vector<int> findAnagrams(string s, string p) {
    //     vector<int> ans;
    //     if(s.size() < p.size()){
    //         return ans;
    //     }
    //     else{
    //         for(int i=0;i<s.size();i++){
    //             string s1 = s.substr(i,p.size());
    //             if(check_anagram(s1,p) == true){
    //                 ans.push_back(i);
    //             }    
    //         }
    //     }
    //     return ans;
    // }

//approch 2: TLE for large inputs
    // bool check_anagram(string s,string t){
    //     sort(s.begin(),s.end());
    //     sort(t.begin(),t.end());
    //     if(s == t){
    //         return true;
    //     }
    //     else{
    //         return false;
    //     }
    // }
    // vector<int> findAnagrams(string s, string p){
    //     vector<int> ans;
    //     if(s == p){
    //         ans.push_back(0);
    //         return ans;
    //     }
    //     else if(s.size() < p.size()){
    //         return ans;
    //     }
    //     else{
    //         for(int i=0;i<s.size();i++){
    //             if(p.find(s[i]) < p.length()){
    //                 //found the letter
    //                 string s1 = s.substr(i,p.size());
    //                 if(check_anagram(s1,p) == true){
    //                     ans.push_back(i);
    //                 }
    //             }
    //         }
    //     }
    //     return ans;
    // }

//apprach 3: TLE 

    // vector<int> findAnagrams(string s, string p){
    //     vector<int> ans;
    //     if(s == p){
    //         ans.push_back(0);
    //         return ans;
    //     }
    //     else if(s.size() < p.size()){
    //         return ans;
    //     }
    //     else{
    //         int i = 0;
    //         int j = p.size()-1;
    //         vector<int> ans;
    //         while(j<s.size()){
    //             int flag = 0;
    //             string temp = p;
    //             for(int k = i;k<=j;k++){
    //                 size_t f = temp.find(s[k]);
    //                 if(f == string :: npos){
    //                     flag = 1;
    //                     break;
    //                 }
    //                 else{
    //                     temp.erase(temp.begin() + f);
    //                 }
    //             }
    //             if(flag == 0){
    //                 ans.push_back(i);
    //             }
    //             j++;
    //             i++;
    //         }
    //         return ans;
    //     }

//appraoch 4: using space  --> TLE 
    // vector<int> findAnagrams(string s, string p){ 
    //     vector<int> ans;
    //     if(s == p){
    //         ans.push_back(0);
    //         return ans;
    //     }
    //     else if(s.size() < p.size()){
    //         return ans;
    //     }
    //     else{
    //         map<char,int> mapp;
    //         for(int i = 0;i<p.size();i++){
    //             mapp[p[i]] = mapp[p[i]] + 1;
    //         }

    //         int i = 0;
    //         int j = p.size()-1;
    //         while(j<s.size()){
    //             map<char,int> maps;
    //             int flag = 1;
    //             for(int k = i;k<=j;k++){
    //                 maps[s[k]] = maps[s[k]] + 1;
    //             }

    //             for(auto it1 = maps.begin(),it2 = mapp.begin();it1 != maps.end();it1++,it2++){
    //                 if(it1->first != it2->first || it1->second != it2->second){
    //                     flag = 0;
    //                     break;
    //                 }
    //             }
    //             if(flag == 1){
    //                 ans.push_back(i);
    //             }
    //             i++;
    //             j++;
    //         }
    //     }
    //     return ans;

//appraoch 5:
    vector<int> findAnagrams(string s, string p){
        vector<int> ans;
        if(s == p){
            ans.push_back(0);
            return ans;
        }
        else if(s.size() < p.size()){
            return ans;
        }
        else{
            map<char ,int> mapp,maps;

            for(int i = 0;i < p.size();i++){
                mapp[p[i]]++;
            }

            for(int i = 0;i< p.size()-1;i++){  //add only k-1 element in the window
                maps[s[i]]++;
            }

            for(int i = p.size()-1;i<s.size();i++){
                maps[s[i]]++;

                if(maps == mapp){
                    ans.push_back(i - p.size() + 1);
                }

                char left = s[i - p.size() + 1];
                if(maps[left] == 1){
                    maps.erase(left);
                }
                else{
                    maps[left]--;
                }
            }
            return ans;
        }
    }    
};