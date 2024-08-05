class Solution {
public:

    int countsplits(vector<int>& nums,int maxsum){
        int split = 1;
        int sum = 0;

        for(int i = 0;i<nums.size();i++){
            if(sum + nums[i] <= maxsum){
                sum = sum + nums[i];
            }
            else{
                sum = nums[i];
                split++;
            }
        }
        return split;
    }


    int splitArray(vector<int>& nums, int k) {
    //approach 1:
        int mini = INT_MIN;
        int maxi = 0;

        for(int i = 0;i<nums.size();i++){
            mini = max(mini,nums[i]);
            maxi = maxi + nums[i];
        }

        for(int i = mini;i<=maxi;i++){
            if(countsplits(nums,i) <= k){
                return i;
            }
        }
        return -1;
    }
};