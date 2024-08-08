class Solution {
public:
    string frequencySort(string s) {
    //brute force:  TC ~ O(n2) and SC ~ O(n) 
        // map<char,int> map;
        // for(auto val : s){
        //     map[val] = map[val] + 1;
        // }

        // string ans = "";

        // while(!map.empty()){
        //     int maxi = INT_MIN;
        //     char cmaxi; 
        //     for(auto val : map){
        //         if(val.second > maxi){
        //             maxi = val.second;
        //             cmaxi = val.first;
        //         }
        //     }

        //     for(int i = 0;i<maxi;i++){
        //         ans.push_back(cmaxi);
        //     }
            
        //     map.erase(cmaxi);
        // }
        
        // return ans;

    //approach 2: bucket sort
        map<char,int> map;
        for(int i = 0;i<s.size();i++){
            map[s[i]]++;
        }

        vector<vector<char>> bucket(s.size()+1);
        for(auto val : map){
            bucket[val.second].push_back(val.first);
        }

        string ans = "";
        for(int i = s.size();i>=1;i--){
            for(int j = 0;j<bucket[i].size();j++){
                for(int k = 1;k<=i;k++){
                    ans.push_back(bucket[i][j]);
                }
            }
        }

        return ans;  

    }
};