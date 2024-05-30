class Solution {
public:
    int singleNumber(vector<int>& nums) {
    //approach 1: using map;
        // map<int,int> map;
        // for(int i = 0;i< nums.size();i++){
        //     map[nums[i]]++;
        // }

        // for(auto val : map){
        //     if(val.second == 1){
        //         return val.first;
        //     }
        // }
        // return 0;

    //appraoch 2:  
        sort(nums.begin(),nums.end());
        int i = 1;
        while(i<nums.size()){
            if(nums[i] != nums[i-1]){
                return nums[i-1];
            }
            i = i + 3;
        }

        return nums[nums.size()-1];
    }
};