class Solution {
public:

    int solve(vector<int>& coins,int amount,long long curr,long long ans){
        if(curr > amount){
            return INT_MAX;
        }
        if(curr == amount){
            return ans;
        }

        int count = INT_MAX;
        for(int i = 0;i<coins.size();i++){
            count = min(solve(coins,amount,curr+coins[i],ans+1),count);
        }
        return count;

    }

    int coinChange(vector<int>& coins, int amount) {
        if(solve(coins,amount,0,0) == INT_MAX){
            return -1;
        }
        return solve(coins,amount,0,0);
    }
};