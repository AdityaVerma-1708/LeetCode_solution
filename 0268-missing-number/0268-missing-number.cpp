class Solution {
public:
    int missingNumber(vector<int>& nums) {
    //appraoch 1: 
        // sort(nums.begin(),nums.end());
        // int i=0;
        // while(i<nums.size()){
        //     if(nums[i] != i){
        //         return i;
        //     }
        //     i++;
        // }
        // return i;
    //approach 2: use space and O(n)
        vector<int> arr(nums.size()+1,0);
        for(int i = 0;i<nums.size();i++){
            arr[nums[i]] = 1;
        }

        for(int i = 0;i<arr.size();i++){
            if(arr[i] == 0){
                return i;
            }
        }
        return 1;
    }
};