class Solution {
public:
    vector<int> decode(vector<int>& encoded, int first) {
    //approach 1: using vector   
        vector<int> ans;
        ans.push_back(first);
        for(int  i = 0;i < encoded.size();i++){
            ans.push_back(ans.back() ^ encoded[i]);
        }

        return ans;

    
    }
};