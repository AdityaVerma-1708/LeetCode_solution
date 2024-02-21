class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
    //appraoch 1: brute force 
        // for(int i=0;i<nums.size();i++){
        //     if(nums[i] == target){  //if target matches nothing is there
        //         return i;
        //     }
        // }

        // for(int i=1;i<nums.size();i++){  
        //     if(target > nums[i-1]){  
        //         if(target < nums[i]){  
        //             return i;   
        //         }
        //     }
        // }

        // if(target < nums[0]){
        //     return 0;
        // }
        // else{
        //     return nums.size();
        // } 
    //appraoch 2: binary search
        

        int i = 0;
        int j = nums.size() - 1;
        while(i <= j){
            int mid = (i+j)/2;
            if(nums[mid] == target){
                return mid;
            }
            else if (nums[mid] > target){
                j = mid - 1;
            }
            else{
                i = mid + 1;
            }
        }
        return i;
    }
};