class Solution {
public:
    int hammingWeight(int n) {
    //approach 1:
        int ans = 0;
        while(n != 0){
            if((n & 1) != 0){
                //bit is non zero
                ans++;
            }
            n = n >> 1;
        }
        return ans;
    }
};