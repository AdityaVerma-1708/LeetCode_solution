class Solution {
public:

//appraoch 1: TLE at 73 /176
    // bool solve(vector<int> nums,int start,int jump){
    //     if((start + jump) == nums.size()-1){
    //         return true;
    //     }

    //     int index = start + jump;
    //     for(int i = 1;i<=nums[index];i++){
    //         bool ans = solve(nums,index,i);
    //         if(ans == true){
    //             return true;
    //         }
    //     }

    //     return false;

    // }

    // bool canJump(vector<int>& nums) {
    //     if(nums.size() == 1){
    //        return true;
    //     }
    //     bool ans;
    //     ans = solve(nums,0,0);
    //     return ans;
    // }

//appraoch 2:  wrong ans for [0,2,3]

    // bool canJump(vector<int>& nums) {
    //     int maxi = 0;
    //     for(int i = 0;i<nums.size()-1;i++){

    //         maxi = max(maxi,i+nums[i]);
    //         if(maxi >= nums.size()-1){
    //             return true;
    //         }
    //     }

    //     if(maxi < nums.size()-1){
    //         return false;
    //     }
    //     else{
    //         return true;
    //     }
    // }   

//approach 3: 
    bool canJump(vector<int>& nums){
        int maxi = 0;
        for(int i = 0;i<nums.size()-1;i++){
            
            if(nums[i] == 0){
                if(maxi > i){
                    continue;
                }
                else{
                    return false;
                }
            }
            maxi = max(maxi,i+nums[i]);
            if(maxi >= nums.size()-1){
                return true;
            }
        }

        if(maxi < nums.size()-1){
            return false;
        }
        else{
            return true;
        }
    }   
};