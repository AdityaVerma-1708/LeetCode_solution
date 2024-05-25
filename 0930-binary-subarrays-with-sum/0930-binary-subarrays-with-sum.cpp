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

        unordered_map<int,int> map;
        int ans = 0;
        int sum = 0;
        for(int i = 0;i< nums.size();i++){
            sum = sum + nums[i];
            map[sum] = map[sum] + 1;

            if(sum >= goal){
                if(sum == goal){
                    ans++;
                }
                auto itr = map.find(sum - goal);
                if(sum - goal == sum){  //means goal is 0
                    if(itr != map.end()){
                        ans = ans + itr->second - 1;
                    }
                }
                else{
                    if(itr != map.end()){
                        ans = ans + itr->second;
                    }
                }
            }
        }
        return ans;

    //approach 3: without space;   // wrong for some test cases
        // int totsum = 0;
        // int currsum = 0;
        // int ans = 0;
        
        // for(int val : nums){
        //     totsum = totsum + val;
        // }

        // for(int val : nums){
        //     currsum = currsum + val;
        //     if(currsum == goal){
        //         ans++;
        //     }

        //     if(totsum - currsum == goal){
        //         ans++;
        //     }
        // }

        // return ans;

    }
};