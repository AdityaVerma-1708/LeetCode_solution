class Solution {
public:
    int minSwaps(vector<int>& nums) {
    //brute force:
        int tot1 = 0;
        int size = nums.size();
        int ans = INT_MAX;
        for(int i = 0;i<size;i++){
            if(nums[i] == 1){
                tot1++;
            }
        }
       
        for(int i = 0;i<size;i++){
            nums.push_back(nums[i]);
        }

        int i = 0;
        int j = 0;
        int zero = 0;
        while(j < nums.size()){
            if(j - i + 1 <= tot1){
                if(nums[j] == 0){
                    zero++;
                }
                j++;
            }
            else{
                ans = min(ans,zero);
                if(nums[i] == 0){
                    zero--;
                }
                i++;
                if(nums[j] == 0){
                    zero++;
                }
                j++;
            }
        }
        return ans;
    }
};