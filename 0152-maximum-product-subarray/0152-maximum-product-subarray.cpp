class Solution {
public:
    int maxProduct(vector<int>& nums) {
    //approach 1: brute force

        // int ans = INT_MIN;
        // for(int i = 0;i<nums.size();i++){
        //     int curr = nums[i];
        //     ans = max(curr,ans);
        //     for(int j = i+1;j<nums.size();j++){
        //         curr = curr * nums[j];
        //         ans = max(ans,curr);
        //     }
        // }
        // return ans;
      
    // approach 2: hasing --> 190 /191 showing overflow 

        // long long ans = LLONG_MIN;
        // long long prod = 1;
        // vector<long long> arr(nums.size(),0);

        // for(int i = 0;i<nums.size();i++){
        //     prod = prod * nums[i];
        //     arr[i] = prod;
        //     if(prod == 0){
        //         prod = 1;
        //     }
        // }   

        // for(int i = 0;i<arr.size();i++){
        //     ans = max(ans,arr[i]);
        //     if(arr[i] < 0){
        //         //check if we can make this positive
        //         int j = i - 1;
        //         while(j >= 0 && arr[j] != 0 ){
        //             ans = max(ans,arr[i]/arr[j]);
        //             j--;
        //         }
        //     }
        // }   
        // return (int)ans;

    //appraoch 3:
        int prefix = 1;
        int suffix = 1;
        int ans = INT_MIN;

        for(int i = 0;i<nums.size();i++){
            prefix = prefix*nums[i];
            ans = max(ans,prefix);
            if(prefix == 0){
                prefix = 1;
            }
        }
            
        for(int i = nums.size()-1;i>=0;i--){
            suffix = suffix*nums[i];
            ans = max(ans,suffix);
            if(suffix == 0){
                suffix = 1;
            } 
        }

        return ans;
    }
};