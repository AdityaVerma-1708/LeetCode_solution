class Solution {
public:
    vector<int> findArray(vector<int>& pref) {
        vector<int> ans;
        int xorr = pref[0];
        ans.push_back(xorr);

        for(int i = 1;i<pref.size();i++){
            ans.push_back(xorr ^ pref[i]);
            xorr = pref[i];
        }

        return ans;
    }
};