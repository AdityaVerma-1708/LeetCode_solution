class Solution {
public:
    int maxSubArray(vector<int>& nums) {
    //approch 1: my brute force ofcourse TLE
        // long int i=0;
        // set<int> set;
        // while(i<nums.size()){
        //     long int sum = i;
        //     long int j = i + 1;
        //     while(sum < sum + j){
        //         sum = sum + j;
        //         j++;
        //     }
        //     set.insert(sum);
        //     sum = 0;
        //     i++;
        // }
        // auto it = set.end();
        // return *it-1;
        
    //approch 2: dp
        if(nums.size() == 0){
            return 0;
        }
        else{
            int maxi = nums[0];
            int curr = nums[0];

            for(int i=1;i<nums.size();i++){
                curr = max(nums[i],curr + nums[i]);
                maxi = max(curr,maxi);

            }
            return maxi;
        }

    }
};