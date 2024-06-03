class Solution {
public:
    bool closeStrings(string word1, string word2) {
    //approach 1:
        if(word1.size() != word2.size()){
            return false;
        }
        else{
            unordered_map<char,int> map1,map2;
            set<char> set1,set2;
            //same letter but can have different occurances

            for(int i = 0;i<word1.size();i++){
                map1[word1[i]]++;
                set1.insert(word1[i]);
            }
            for(int i = 0;i<word2.size();i++){
                map2[word2[i]]++;
                set2.insert(word2[i]);
            }

            if(set1 != set2){
                return false;
            }
            else{
                vector<int> vec1,vec2;
                for(auto val : map1){
                    vec1.push_back(val.second);
                }

                for(auto val : map2){
                    vec2.push_back(val.second);
                }

                sort(vec1.begin(),vec1.end());
                sort(vec2.begin(),vec2.end());

                if(vec1 == vec2){
                    return true;
                }
                else{
                    return false;
                }
            }
        }                
    }
};