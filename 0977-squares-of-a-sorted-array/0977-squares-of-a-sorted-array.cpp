class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
    //with using extra space
        vector<int> ans(nums.size(),-1);
        int i = 0;
        int j = nums.size()-1;
        int k = j;
        while(i<=j && k>=0){
            if(nums[j]*nums[j] > nums[i]*nums[i]){
                ans[k] = nums[j]*nums[j];
                j--;
            }
            else{
                ans[k] = nums[i]*nums[i];
                i++;
            }
            k--;
        }
        return ans;
    }
};