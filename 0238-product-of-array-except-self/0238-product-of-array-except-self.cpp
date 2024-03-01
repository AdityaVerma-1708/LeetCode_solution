class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
    //appraoch 1: brute force  --> TLE
        // vector<int> ans(nums.size(),-1);
        // for(int i = 0;i<nums.size();i++){
        //     int prod = 1;
        //     for(int j = 0;j<nums.size();j++){
        //         if(i != j){
        //             prod = prod * nums[j];
        //         }
        //     }
        //     ans[i] = prod;
        // }
        // return ans;

    //approach 2: prefix and postfix
        vector<int> ans(nums.size(),-1);

        int pre = 1;
        for(int i = 0;i<nums.size();i++){
            ans[i] = pre;
            pre = pre * nums[i];  
        }

        int post = 1;
        for(int i = nums.size()-1;i>=0;i--){
            ans[i] = ans[i] * post;
            post = post * nums[i];
        }

        return ans;
    }
};