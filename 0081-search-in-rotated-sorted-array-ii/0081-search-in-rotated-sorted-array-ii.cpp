class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int i = 0;
        int j = nums.size()-1;
        while(i <= j){
            int mid = (i+j)/2;
            if(nums[mid] == target){
                return true;
            }
            else if (nums[mid] == nums[i]){
                i++;
            }
            else if(nums[mid] == nums[j]){
                j--;
            }
            else if(nums[mid] == nums[i] && nums[mid] == nums[j]){
                i++;
                j--;
            }
            else if (nums[mid] > nums[i]){
                if(target <= nums[mid] && target >= nums[i]){
                    j = mid - 1;
                }
                else{
                    i = mid + 1;
                }
            }
            else{
                if(target >= nums[mid] && target <= nums[j]){
                    i = mid + 1;
                }
                else{
                    j = mid - 1;
                }
            }
        }
        return false;
    }
};