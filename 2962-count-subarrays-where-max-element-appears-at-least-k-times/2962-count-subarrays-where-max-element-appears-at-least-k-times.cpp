class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
    //brute force;  TLE for tc 622
        // int maxi = INT_MIN;
        // for(auto val : nums){
        //     if(val > maxi){
        //         maxi = val;
        //     }
        // }

        // int count = 0;
        // int ans = 0;
        // for(int i = 0;i<nums.size();i++){
        //     for(int j = i;j<nums.size();j++){
        //         if(nums[j] == maxi){
        //             count++;
        //         }

        //         if(count >= k){
        //             ans++;
        //         }
        //     }
        //     count = 0;
        // }
        // return ans;

    //approach 2: little optimize tle  for tc 625 out of 633
        // int maxi = INT_MIN;
        // for(auto val : nums){
        //     if(val > maxi){
        //         maxi = val;
        //     }
        // }

        // int count = 0;
        // int ans = 0;

        // for(int i = 0;i<nums.size();i++){
        //     for(int  j = i;j<nums.size();j++){
        //         if(nums[j] == maxi){
        //             count++;
        //         }

        //         if(count == k){
        //             ans = ans + nums.size() - j;
        //             break;
        //         }
        //     }
        //     count = 0;
        // }

        // return ans;

    //approach 3: optimize 

        int maxi = INT_MIN;
        for(auto val : nums){
            if(val > maxi){
                maxi = val;
            }
        }

        long long ans = 0;
        long long count = 0;
        int i = 0;
        int j = 0;
        int flag = 0;
        while(j < nums.size()){

            if(nums[j] == maxi && flag == 0){
                count++;
            } 

            flag = 0;
            
            if(count == k){
                ans = ans + nums.size() - j;
                flag = 1;
                if(nums[i] == maxi){
                    count--;
                    // i++;
                }
                // else if(nums[i] != maxi){
                //     i++;
                // }
                i++;
            }
            else{
                j++;

            }
        }
        return ans;
    }
};