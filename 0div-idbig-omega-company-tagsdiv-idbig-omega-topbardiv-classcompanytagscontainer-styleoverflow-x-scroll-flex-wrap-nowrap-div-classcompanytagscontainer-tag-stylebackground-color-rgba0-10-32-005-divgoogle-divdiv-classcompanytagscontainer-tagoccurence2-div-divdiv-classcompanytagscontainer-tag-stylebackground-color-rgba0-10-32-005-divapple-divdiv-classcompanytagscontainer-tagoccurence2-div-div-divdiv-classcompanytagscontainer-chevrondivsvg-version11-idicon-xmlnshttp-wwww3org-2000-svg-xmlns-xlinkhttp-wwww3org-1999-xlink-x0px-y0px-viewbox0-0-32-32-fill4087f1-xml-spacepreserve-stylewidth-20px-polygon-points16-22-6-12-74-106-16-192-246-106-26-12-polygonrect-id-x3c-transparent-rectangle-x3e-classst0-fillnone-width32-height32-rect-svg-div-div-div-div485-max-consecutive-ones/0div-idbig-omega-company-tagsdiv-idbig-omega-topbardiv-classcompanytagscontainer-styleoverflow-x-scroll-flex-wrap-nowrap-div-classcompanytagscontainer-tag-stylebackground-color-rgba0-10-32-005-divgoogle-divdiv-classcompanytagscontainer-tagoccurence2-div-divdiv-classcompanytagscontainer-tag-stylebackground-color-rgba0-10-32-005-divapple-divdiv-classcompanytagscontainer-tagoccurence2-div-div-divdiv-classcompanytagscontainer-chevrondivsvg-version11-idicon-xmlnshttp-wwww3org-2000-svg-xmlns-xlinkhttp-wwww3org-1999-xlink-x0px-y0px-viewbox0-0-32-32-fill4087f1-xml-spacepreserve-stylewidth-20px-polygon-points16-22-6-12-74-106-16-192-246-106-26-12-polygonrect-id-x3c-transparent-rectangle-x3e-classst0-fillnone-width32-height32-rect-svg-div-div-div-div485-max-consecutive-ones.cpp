class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
    //appraoch 1: O(n2)
        // int ans = 0; 
        // for(int i = 0;i < nums.size();i++){
        //     int count = 0;
        //     for(int j = i;j<nums.size();j++){
        //         if(nums[j] == 1){
        //             count++;
        //         }
        //         else{
        //             break;
        //         }
        //     }
        //     ans = max(ans,count);
        // }
        // return ans;
        
    //appraoch 2: O(n)-->sliding window
        int i = 0;
        int j = 0;
        int ans = 0;
        int count = 0;
        while(j < nums.size()){
            if(nums[i] == 0){
                i++;
                j++;
            } 
            else if (nums[j] == 1){
                count++;
                j++;
            }       
            else if(nums[j] == 0){
                ans = max(ans,count);
                count = 0;
                i = j;
            }     
        }
        ans = max(ans,count);
        return ans;
    }
};