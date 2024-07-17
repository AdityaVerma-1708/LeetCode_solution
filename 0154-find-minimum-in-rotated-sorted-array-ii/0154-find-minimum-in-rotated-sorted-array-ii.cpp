class Solution {
public:
    int findMin(vector<int>& nums) {
        int ans = INT_MAX;
        int i = 0;
        int j = nums.size()-1;
        if(nums.size() == 1){
            return nums[0];
        }
        else if(nums[i] < nums[j]){
            return nums[i];
        }
        else{
            while(i <= j){
                int mid = (i+j)/2;

                if(nums[mid] >= nums[i]){
                    if(ans > nums[i]){
                        ans = nums[i];
                    }
                    i = mid + 1;
                }
                else{ // nums[mid] <= nums[j]
                    if(ans > nums[mid]){
                        ans = mid;
                    }
                    j = mid - 1;
                }
            }
            return ans;
        }
    }
};