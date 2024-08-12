class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        if(nums.size() < k){
            return {-1};
        }
        vector<int> ans(nums.size(),-1);
        int size = 2*k + 1;
        int i = 0;
        int j = 0;
        int mid = k;
        int sum = 0;

        while(j < nums.size()){
            if(j - i + 1 <= size){
                sum = sum + nums[j];
                j++;
            }
            else{
                ans[mid] = sum/size;
                mid++;
                sum = sum - nums[i];
                i++;
                sum = sum + nums[j];
                j++;
            }
        }
        ans[mid] = sum/size;
        return ans;
    }
};