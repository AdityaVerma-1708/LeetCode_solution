class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
    //approach 1: O()

        if(nums.size() <= 1){
            return nums.size();
        }
        sort(nums.begin(),nums.end());
        int i = 0;
        int j = 1;
        int ans = 0;
        int rep = 0;

        while(j < nums.size()){
            if(nums[j] - nums[j-1] == 1){
                j++;
            }
            else if( nums[j] - nums[j-1] == 0){
                j++;
                rep++;
            }
            else{
                ans = max(ans,j-i-rep);
                i = j;
                j++;
                rep = 0;
            }
        }

        ans = max(ans,j-i-rep);
        return ans;
    }
};