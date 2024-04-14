class Solution {
public:

    // int solve(int i,int j,vector<int>& nums){
    //     //base case
        
    // }

    int singleNonDuplicate(vector<int>& nums) {
    //approach 1: checking every elements neighbour O(n);
        // int ans = -1;
        // int i = 1;
        // while(i<nums.size()){
        //     if(nums[i] != nums[i-1]){
        //         return nums[i-1];
        //     }
        //     i = i+2;
        // }
        // if(ans == -1){
        //     ans = nums.back();
        // }
        // return ans;

    //approach 2: using xor
        // int ans = nums[0];
        // for(int i = 1;i<nums.size();i++){
        //     ans = ans ^ nums[i];
        // }
        // return ans;

    //approach 3: O(logn)
        if(nums.size() == 1){
            return nums[0];
        }

        int i = 0;
        int j = nums.size()-1;
        int ans = -1;

        if(nums[0] != nums[1]){
            return nums[0];
        }
        else if (nums[nums.size()-1] != nums[nums.size()-2]){
            return nums[nums.size()-1];
        }
        else{
            //basiacally before single element every number will on (even, odd) index
            //but after single they eilll be on (odd, even)
            //binary search 

            while(i<=j){
                int mid = (i+j)/2;
                if(nums[mid] != nums[mid-1] && nums[mid] != nums[mid+1]){
                    return nums[mid];
                }
                else if (mid % 2 != 0 && nums[mid] == nums[mid+1]){
                    //making pair as (odd,even) => single ele is present in left part
                    j = mid - 1;
                }
                else if(mid % 2 == 0 && nums[mid] == nums[mid-1]){
                    //making pair as (odd,even) => single ele is present in left part
                    j = mid - 1;
                }
                else if(mid % 2 != 0 && nums[mid] == nums[mid-1]){
                    //making pair as (even,odd) => single ele is present in right part
                    i = mid + 1;
                }
                else{
                    //making pair as (even,odd) => single ele is present in right part
                    i = mid + 1;
                }

            }
        }
        return 1;
    }
};