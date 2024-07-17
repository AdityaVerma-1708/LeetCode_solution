class Solution {
public:
    int findMin(vector<int>& nums) {
    //approach 1:
        // sort(nums.begin(),nums.end());
        // return nums[0]; 

    //appraoch 2: double pointer
        // int i = 0;
        // int j = nums.size()-1;
        // if(nums.size() <= 1){
        //     return nums[0];
        // }
        // else if(nums[i] < nums[j]){
        //     //not rotated
        //     return nums[0];
        // }
        // else{
        //     //rotated
        //     while(nums[j] > nums[j-1] && i<j){
        //         j--;
        //     }
        //     return nums[j];
        // }

    //approach 3: binary search 
        // int i = 0;
        // int j = nums.size()-1;

        // if(nums.size() == 1){
        //     return nums[0];
        // }
        // else if(nums[i] < nums[j]){
        //     //not rotated
        //     return nums[0];  
        // }
        // else{
        //     while(j-i != 1){
        //         int mid = (i+j)/2;
        //         if(nums[mid] > nums[i]){
        //             i = mid;
        //         }
        //         else{
        //             j = mid;
        //         }
        //     }
        //     return nums[j];
        // }

    //practice:
        int i = 0;
        int j = nums.size()-1;
        if(nums.size() == 1){
            return nums[0];
        }
        else if(nums[i] < nums[j]){
            //not rotated
            return nums[0];  
        }
        else{
            int ans = INT_MAX;
            while(i <= j){
                int mid = (i+j)/2;
                if(nums[mid] >= nums[i]){
                    ans = min(nums[i],ans);
                    i = mid + 1;
                }
                else{
                    //nums[mid] < nums[j]
                    ans = min(nums[mid],ans);
                    j = mid - 1;
                }
            }
            return ans;
        }

    }
};