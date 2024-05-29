class Solution {
public:
    int minBitFlips(int start, int goal) {
    //approach 1;
        int num = start ^ goal;
        int ans = 0;
        while(num != 0){
            if((num & 1) == 1){
                ans++;
            }
            num = num >> 1;
        }

        return ans;
    }
};