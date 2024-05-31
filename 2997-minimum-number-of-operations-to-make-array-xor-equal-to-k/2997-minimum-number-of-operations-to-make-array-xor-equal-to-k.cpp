class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int xorr = 0;
        for(int i = 0;i< nums.size();i++){
            xorr = xorr ^ nums[i];
        }

        int num = xorr ^ k;
        int setbits = 0;
        while(num != 0){
            if(num & 1 != 0){
                setbits++;
            }
            num = num >> 1;
        }

        return setbits;


    }
};