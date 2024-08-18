class Solution {
public:
    int minOperations(vector<int>& nums) {
    //brute force:
        int i = 0;
        int j = 0;
        int ans = 0;
        while(j < nums.size()){
            if(j - i + 1 <= 3){
                j++;
            }
            else{
                if(nums[i] == 1){
                    i++;
                }
                else{
                    for(int k = i;k<j;k++){
                        nums[k] = nums[k] ^ 1;
                    }
                    ans++;
                    i++;
                }
                j++;
            }
        }

        //last subarray ko consider karo
        //either all should be 1 or all should be 0;
        int num0 = 0;
        for(int k = i;k<j;k++){
            if(nums[k] == 0){
                num0++;
            }
        }
        if(num0 == 3){
            ans++;
        }
        else if(num0 > 0 && num0 < 3){
            return -1;
        }
        
        return ans;
    }
};