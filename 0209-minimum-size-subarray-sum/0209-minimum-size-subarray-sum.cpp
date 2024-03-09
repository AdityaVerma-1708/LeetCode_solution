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

        //here in this method we are shoftinh the j to i directly that improves the time complexity
        //but for that we need to subtract j also while reducing the size since every iteration 
        //nums[j] is adding to currsum which can include duplicates hence we are decrementing the 
        //nums[j] also when currsum >= target

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