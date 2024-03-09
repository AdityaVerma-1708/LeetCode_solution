class Solution {
public:

    int solve(int i,int j,vector<int> &nums){
        
        if(j-i <= 1){
            return -1;
        }


        int mid = (i+j)/2;

        if(nums[mid] > nums[mid+1] && nums[mid] > nums[mid-1]){
            return mid;
        }
        else{
            int a = solve(i,mid,nums);

            if(a == -1){
                a = solve(mid,j,nums);
            }

            return a;
        }
    }

    int findPeakElement(vector<int>& nums) {
        if(nums.size() == 1){
            return 0;
        }
        else if(nums.size() == 2){
            if(nums[0] > nums[1]){
                return 0;
            }
            else if (nums[0] < nums[1]){
                return 1;
            }
        }
        else{
            //check edge cases before only
            if(nums[0] > nums[1]){
                return 0;
            }
            else if (nums[nums.size()-1] > nums[nums.size()-2]){
                return nums.size()-1;
            }

            return solve(0,nums.size()-1,nums);
        }
        return -1;
    }
};