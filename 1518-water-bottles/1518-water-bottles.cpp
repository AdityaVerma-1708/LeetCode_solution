class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int remainder = 0;
        int newBottles = 0;
        int ans = 0;
        
        while(numBottles >= numExchange){
            newBottles = numBottles/numExchange;
            remainder = numBottles % numExchange;
            ans = ans + (numExchange * newBottles);
            numBottles = remainder + newBottles;
        }

        ans = ans + numBottles;
        return ans;
    }
};