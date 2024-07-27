class Solution {
public:
    int maxProfit(vector<int>& prices) {
    //approch 1: TLE on test case 200
        // int max = 0;
        // for(int i = 0;i<prices.size()-1;i++){
        //     int buy = prices[i];
        //     for(int j = i + 1;j<prices.size();j++ ){
        //         int sell = prices[j];
        //         if(sell -  buy > max){
        //             max = sell - buy;
        //         } 
        //     }
        // } 
        // return max;

    //approch 2:
        // int minn = prices[0];
        // int profit = 0;
        // for(int i=1;i<prices.size();i++){
        //     profit = max(profit,prices[i] - minn);
        //     minn = min(minn,prices[i]);
        // }
        // return profit;  

    //practice:
        int mini = prices[0];
        int ans = 0;
        for(int i = 1;i<prices.size();i++){
            if(prices[i] > mini){
                ans = max(ans,prices[i] - mini);
            }
            else{
                mini = min(mini,prices[i]);
            }
        }  
        return ans;
    }
};