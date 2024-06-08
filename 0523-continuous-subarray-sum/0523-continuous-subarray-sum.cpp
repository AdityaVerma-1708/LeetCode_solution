class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
    //approach 1: brute force: TLE for 94 test case
        // if(nums.size() < 2){
        //     return false;
        // }
        // else if(nums.size() == 2){
        //     if((nums[0] + nums[1]) % k == 0){
        //         return true;
        //     }
        //     else{
        //         return false;
        //     }
        // }
        // else{
        //     int sum = nums[0] + nums[1];
            
        //     if(sum % k == 0){
        //         return true;
        //     }

        //     int i = 0;
        //     int j = 1;

        //     while(j < nums.size() && i < nums.size()){
        //         if(sum % k == 0){
        //             return true;
        //         }
        //         if(j == nums.size()-1){
        //             i++;
        //             sum = nums[i] + nums[i+1];
        //             j = i + 1;
        //         }
        //         else{
        //             j++;
        //             sum = sum + nums[j];
        //         }
        //     }
        //     return false;
        // }

    //appraoch 2: 
        if(nums.size() < 2){
            return false;
        }
        else if(nums.size() == 2){
            if((nums[0] + nums[1]) % k == 0){
                return true;
            }
            return false;
        }
        else{
            map<int,int> map;
            int sum = 0;
            map[0] = -1;
            for(int i = 0;i<nums.size();i++){
                sum = sum + nums[i];
                int rem = sum % k;
                if(map.find(rem) != map.end()){
                    if(i - map[rem]  > 1){
                        return true;
                    }
                }
                else{
                    map[rem] = i;
                }
            }
            return false;

        }

    }
};