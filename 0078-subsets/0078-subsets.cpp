class Solution {
public:

    void solve(vector<int> nums,vector<int> op,int i, vector<vector<int>> &ans){
        if(i >= nums.size()){
            ans.push_back(op);
            return ;
        }

        //exclude
        solve(nums,op,i+1,ans);

        //include
        op.push_back(nums[i]);
        solve(nums,op,i+1,ans);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
    //approch 1: very very important question --recurrsion
        vector<vector<int>> ans;
        vector<int> op;
        int i = 0;
        solve(nums,op,i,ans);
        return ans;
    }
};