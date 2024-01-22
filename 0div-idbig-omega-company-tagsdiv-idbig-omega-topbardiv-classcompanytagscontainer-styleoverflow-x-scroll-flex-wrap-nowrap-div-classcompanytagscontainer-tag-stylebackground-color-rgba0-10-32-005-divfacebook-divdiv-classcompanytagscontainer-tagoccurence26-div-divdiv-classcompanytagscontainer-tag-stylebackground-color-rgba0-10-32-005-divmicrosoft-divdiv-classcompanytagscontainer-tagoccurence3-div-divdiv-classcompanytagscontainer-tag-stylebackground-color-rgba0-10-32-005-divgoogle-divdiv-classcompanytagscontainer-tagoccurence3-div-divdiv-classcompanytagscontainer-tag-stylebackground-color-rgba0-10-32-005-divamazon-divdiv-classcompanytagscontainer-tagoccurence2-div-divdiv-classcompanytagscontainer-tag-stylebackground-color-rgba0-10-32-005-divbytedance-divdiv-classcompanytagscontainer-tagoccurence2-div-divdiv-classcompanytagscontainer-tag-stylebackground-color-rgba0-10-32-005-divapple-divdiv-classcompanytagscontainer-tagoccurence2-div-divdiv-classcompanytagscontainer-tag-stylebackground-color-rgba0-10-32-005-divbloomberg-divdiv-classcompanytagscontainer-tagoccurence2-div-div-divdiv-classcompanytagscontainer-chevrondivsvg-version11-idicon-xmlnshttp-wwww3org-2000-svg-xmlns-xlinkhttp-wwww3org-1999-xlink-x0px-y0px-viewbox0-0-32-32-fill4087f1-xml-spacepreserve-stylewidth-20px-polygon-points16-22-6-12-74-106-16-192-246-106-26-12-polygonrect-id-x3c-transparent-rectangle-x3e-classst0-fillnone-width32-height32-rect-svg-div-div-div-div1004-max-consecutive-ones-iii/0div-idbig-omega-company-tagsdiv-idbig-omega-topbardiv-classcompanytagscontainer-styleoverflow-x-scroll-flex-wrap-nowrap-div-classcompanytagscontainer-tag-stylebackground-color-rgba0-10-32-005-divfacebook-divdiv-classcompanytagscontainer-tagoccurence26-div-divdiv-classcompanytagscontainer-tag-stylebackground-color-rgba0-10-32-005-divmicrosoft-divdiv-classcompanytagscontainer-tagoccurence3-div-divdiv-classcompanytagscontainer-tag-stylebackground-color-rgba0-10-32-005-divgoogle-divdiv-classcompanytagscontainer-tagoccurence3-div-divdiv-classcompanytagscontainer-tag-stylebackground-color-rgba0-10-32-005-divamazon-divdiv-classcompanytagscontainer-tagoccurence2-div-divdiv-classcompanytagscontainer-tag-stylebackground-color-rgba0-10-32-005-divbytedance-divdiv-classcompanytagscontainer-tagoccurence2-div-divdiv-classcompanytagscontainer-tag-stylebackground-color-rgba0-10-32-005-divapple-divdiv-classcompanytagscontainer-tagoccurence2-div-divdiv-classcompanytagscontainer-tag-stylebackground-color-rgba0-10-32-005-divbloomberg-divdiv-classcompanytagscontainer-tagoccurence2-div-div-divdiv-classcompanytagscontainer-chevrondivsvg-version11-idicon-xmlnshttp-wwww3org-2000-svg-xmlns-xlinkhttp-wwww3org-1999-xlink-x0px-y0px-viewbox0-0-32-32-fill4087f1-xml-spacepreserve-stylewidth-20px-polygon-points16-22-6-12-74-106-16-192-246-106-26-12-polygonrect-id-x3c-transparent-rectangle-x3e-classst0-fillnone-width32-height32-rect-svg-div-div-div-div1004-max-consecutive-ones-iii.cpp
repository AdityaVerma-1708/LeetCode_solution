class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
    //approach 1:
        int i = 0;
        int j = 0;
        int ans = 0;
        int count = 0;
        while(j < nums.size()){
            if(nums[j] == 1){
                count++;
                j++;
            }
            else if(nums[j] == 0 && k != 0){
                count++;
                k--;
                j++;
            }
            else if(nums[j] == 0 && k == 0){
                ans = max(count,ans);
                if(nums[i] == 0){
                    k++;
                }
                count--;
                i++;
            }
        }
        ans = max(ans,count);
        return ans;
    }
};