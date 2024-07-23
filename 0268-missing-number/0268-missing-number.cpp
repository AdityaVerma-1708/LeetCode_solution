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
        // vector<int> arr(nums.size()+1,0);
        // for(int i = 0;i<nums.size();i++){
        //     arr[nums[i]] = 1;
        // }

        // for(int i = 0;i<arr.size();i++){
        //     if(arr[i] == 0){
        //         return i;
        //     }
        // }
        // return 1;

    //approach 3:
        int n = nums.size();
        int sum1 = n*(n+1)/2;
        int sum2 = 0;
        for(int i = 0;i<n;i++){
            sum2 = sum2 + nums[i];
        }

        return sum1 - sum2;

    //appraoch 4: using xor 
    }
};