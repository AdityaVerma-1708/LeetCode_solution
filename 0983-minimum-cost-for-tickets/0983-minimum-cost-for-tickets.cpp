class Solution {
public:

//appraoch 1: recurrsion TLE @26/70
    // int solve(vector<int>& days,vector<int>& costs,int i){
    //     if(i > days.back()){ //base case
    //         return 0;
    //     }

    //     int day = 0;
    //     for(int j = 0;j<days.size();j++){
    //         if(i <= days[j]){
    //             day = days[j];
    //             break;
    //         }
    //     }

    //     int cost1 = costs[0] + solve(days,costs,day+1);
    //     int cost7 = costs[1] + solve(days,costs,day+7);
    //     int cost30 = costs[2] + solve(days,costs,day+30);


    //     return min({cost1,cost7,cost30});
    // }

    // int mincostTickets(vector<int>& days, vector<int>& costs) {
    //     return solve(days,costs,days[0]);
    // }


//approach 2: DP memoizationm

    int solve(vector<int>& days,vector<int>& costs,int i,vector<int>& dp){
        if(i > days.back()){ //base case
            return 0;
        }

        int day = 0;
        for(int j = 0;j<days.size();j++){
            if(i <= days[j]){
                day = days[j];
                break;
            }
        }

        if(day > days.back()){
            return 0;
        }

        if(dp[day] != -1){
            return dp[day];
        }


        int cost1 = costs[0] + solve(days,costs,day+1,dp);
        int cost7 = costs[1] + solve(days,costs,day+7,dp);
        int cost30 = costs[2] + solve(days,costs,day+30,dp);


        return dp[day] = min({cost1,cost7,cost30});
    }

    int mincostTickets(vector<int>& days, vector<int>& costs) {
        vector<int> dp(365,-1);
        return solve(days,costs,days[0],dp);
    }
};