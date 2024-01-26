class Solution {
public:

    void solve(vector<int>& nums,set<vector<int>>& set,vector<int> op,int i){
        if(i >= nums.size()){
            sort(op.begin(),op.end());
            set.insert(op);
            return;
        }

        //exclude
        solve(nums,set,op,i+1);

        //include
        op.push_back(nums[i]);
        solve(nums,set,op,i+1);
        // op.pop_back();
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans;
        set<vector<int>> set;
        vector<int> op;

        solve(nums,set,op,0);

        for(auto val : set){
            ans.push_back(val);
        }
        return ans;

    }
};