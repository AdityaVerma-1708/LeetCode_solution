class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
    //appraoch 1: brute force  TLE
        // int ans = 0;
        // for(int i = 0;i<nums.size();i++){
        //     int sum = 0;
        //     for(int j = i;j<nums.size();j++){
        //         sum = sum + nums[j];
        //         if(sum == goal){
        //             ans++;
        //         }
        //         else if(sum > goal){
        //             sum = 0;
        //             break;
        //         }
        //     }
        // }
        // return ans++;


    //approach 2: little optimization   -> //prefix sum with space    
    
        // map<int,int> map;
        // int sum = 0;
        // int ans = 0;
        // for(int i = 0;i<nums.size();i++){
        //     sum = sum + nums[i];
        //     map[sum] = map[sum] + 1;

        //     if(sum == goal){
        //         ans++;
        //         auto itr = map.find(sum - goal);
        //         if(sum - goal == sum){
        //             if(itr != map.end()){
        //                 ans = ans + itr->second - 1;
        //             }
        //         }
        //         else{
        //             if(itr != map.end()){
        //                 ans = ans + itr->second;
        //             }
        //         }
        //     } 
        //     if(sum > goal){
        //         auto itr = map.find(sum - goal);
        //         if(sum - goal == sum){             //4-0 = 4
        //             if(itr != map.end()){
        //                 ans = ans + itr->second - 1;
        //             }
        //         }
        //         else{
        //             if(itr != map.end()){
        //                 ans = ans + itr->second;
        //             }
        //         }    
        //     } 
        // }
        // return ans;


    //approach -> cleaned approach 2

        // unordered_map<int,int> map;
        // int ans = 0;
        // int sum = 0;
        // for(int i = 0;i< nums.size();i++){
        //     sum = sum + nums[i];
        //     map[sum] = map[sum] + 1;

        //     if(sum >= goal){
        //         if(sum == goal){
        //             ans++;
        //         }
        //         auto itr = map.find(sum - goal);
        //         if(sum - goal == sum){  //means goal is 0
        //             if(itr != map.end()){
        //                 ans = ans + itr->second - 1;
        //             }
        //         }
        //         else{
        //             if(itr != map.end()){
        //                 ans = ans + itr->second;
        //             }
        //         }
        //     }
        // }
        // return ans;

    //practice
        vector<int> map(nums.size(),0);
        int sum = 0;
        int ans = 0;
        for(int i = 0;i<nums.size();i++){
            sum = sum + nums[i];
            map[i] = sum;
        }

        for(int i = 0;i<map.size();i++){
            if(map[i] == goal){
                ans++;
                for(int j = 0;j<i;j++){
                    if((map[i] - map[j]) == goal){
                        ans++;
                    }
                }
            }
            else if (map[i] > goal){
                for(int j = 0;j<i;j++){
                    if((map[i] - map[j]) == goal){
                        ans++;
                    }
                }
            }
        }

        return ans;

    }
};