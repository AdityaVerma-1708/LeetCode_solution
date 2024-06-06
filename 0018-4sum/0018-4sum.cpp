class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
    //approach 1: brute force wrong ans;
        set<vector<int>> set;
        vector<vector<int>> ans;
        sort(nums.begin(),nums.end());
        if(nums.size() < 4){
            return ans;
        }
        else{
            for(int i = 0;i<nums.size()-3;i++){
                for(int j = i+1;j<nums.size()-2;j++){
                    for(int k = j+1;k<nums.size()-1;k++){
                        for(int l = k+1;l<nums.size();l++){
                            long long sum = (long long )nums[i] + (long long)nums[j] + (long long)nums[k] + (long long)nums[l];
                            if(sum == target){
                                set.insert({nums[i],nums[j],nums[k],nums[l] });
                            }
                        }
                    }
                }
            }
            for(auto val : set){
                ans.push_back(val);
            }
            return ans;
        }
    }
};