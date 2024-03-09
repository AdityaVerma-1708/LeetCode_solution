class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
    //appraoch 1: sliding window
        // int ans = nums.size()+1;
        // int i = 0;
        // int j = 0;
        // int currsum = 0;
        // while(j<nums.size()){
        //     currsum = currsum + nums[j];
        //     if(currsum >= target){
        //         ans = min(ans,j-i+1);
        //         i++;
        //         j = i;
        //         currsum = 0;
        //     }
        //     else{
        //         j++;
        //     }
        // }
        
        // if(ans == nums.size()+1){
        //     ans = 0;
        // }
        // else{
        //     ans = min(ans,j-i+1);
        // }
        // return ans;

    //appraoch 2: sliding window optimization
        int ans = nums.size()+1;
        int i = 0;
        int j = 0;
        int currsum = 0;
        while(j<nums.size()){
            currsum = currsum + nums[j];
            if(currsum >= target){
                ans = min(ans,j-i+1);
                currsum = currsum - nums[i];
                currsum = currsum - nums[j];
                i++;
            }
            else{
                j++;
            }
        }
        if(ans == nums.size()+1){
            ans = 0;
        }
        else{
            ans = min(ans,j-i+1);
        }
        return ans;
    }
};