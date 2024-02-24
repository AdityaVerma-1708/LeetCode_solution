class Solution {
public:
    vector<int> findLonely(vector<int>& nums) {
    //appraoch 1: using sorting and a loop
        // if(nums.size() == 1){
        //     return nums;
        // }
        // sort(nums.begin(),nums.end());
        // int i = 0;
        // vector<int> ans;
        // while(i<nums.size()){
        //     if(i == 0){
        //         if(nums[i] != nums[i+1] && nums[i+1] != (nums[i]+1)){
        //             ans.push_back(nums[i]);
        //         }
        //         i++;
        //     }
        //     else if(i == nums.size()-1){
        //         if(nums[i] != nums[i-1] && (nums[i-1] != nums[i]-1)){
        //             ans.push_back(nums[i]);
        //         }
        //         i++;
        //     }
        //     else{
        //         if(nums[i] != nums[i+1] && nums[i] != nums[i-1] && nums[i+1] != (nums[i]+1) && nums[i-1] != (nums[i]-1)){
        //             ans.push_back(nums[i]);
        //         }
        //         i++;
        //     }
        // }
        // return ans;

    //approach 2: using map
        if(nums.size() == 1){
            return nums;
        }
        map<int,int> map;
        vector<int> ans;
        for(int val : nums){
            map[val]++;
        } 

        for(auto val : map){
            if(val.second == 1){
                if(map.find(val.first - 1) == map.end()  && map.find(val.first + 1) == map.end()){
                    ans.push_back(val.first);
                }
            }
        }
        return ans;
    }
};