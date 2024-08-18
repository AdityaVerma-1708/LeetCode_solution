class Solution {
public:
    int minSwaps(vector<int>& nums) {
    //brute force:
        int tot1 = 0;
        for(int i = 0;i<nums.size();i++){
            if(nums[i] == 1){
                tot1++;
            }
        }

        if(nums.size() == 1){
            return 0;
        }

        //find longest window
        int i = 0;
        int j = 0;
        int count = 0;
        int length = 0;
        int maxi = 0;
        while(count <= nums.size()){
            if(nums[j] == 1){
                if(j == nums.size()-1){
                    j = 0;
                }
                else{
                    j++;
                }
                length++;
                count++;
            }
            else{
                maxi = max(maxi,length);
                if(j == nums.size()-1){
                    j = 0;
                }
                else{
                    j++;
                }
                i = j;
                length = 0;
            }
        }
        return tot1 - maxi;
    }
};