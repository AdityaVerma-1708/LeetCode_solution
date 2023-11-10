class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
    //approch 1:
        vector<int> ans;
        for(int i = 0;i<nums.size();i++){
            int a = nums[i];
            int j = (i+1)%nums.size();
            int flag = 0;
            while(j != i){
                if(a < nums[j]){
                    ans.push_back(nums[j]);
                    flag = 1;
                    break;
                }
                j = (j + 1)%nums.size();
            }
            if(flag == 0){
                ans.push_back(-1);
            }
            flag = 0;
        }
        return ans;
    }
};