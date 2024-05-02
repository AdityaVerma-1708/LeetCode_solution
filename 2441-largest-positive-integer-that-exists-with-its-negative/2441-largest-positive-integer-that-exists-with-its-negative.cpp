class Solution {
public:
    int findMaxK(vector<int>& nums) {
    //approach 1: tc -> O(nlogn)    
        sort(nums.begin(),nums.end());

        int i = 0;
        int j = nums.size()-1;

        if(nums[j] < 0 || nums[i] > 0){
            //all are negative or all the positive
            return -1;
        }
        else{
            int ans = -1;
            while(i<j){
                if(abs(nums[i]) == nums[j]){
                    ans = nums[j];
                    break;
                }
                else if(abs(nums[i]) > nums[j]){
                    i++;
                }
                else if(abs(nums[i]) < nums[j]){
                    j--;
                }
            }
            return ans;
        }
    }
};