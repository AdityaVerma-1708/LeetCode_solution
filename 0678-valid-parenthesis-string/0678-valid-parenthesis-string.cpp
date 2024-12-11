class Solution {
public:
//appraoch 1: TLE @ 7/83   TC 3^n
    // bool solve(string s,int i,int val){
    //     if(i >= s.size()){
    //         if(val == 0){
    //             return true;
    //         }
    //         else{
    //             return false;
    //         }
    //     }

    //     if(s[i] == '('){
    //         return solve(s,i+1,val+1);
    //     }
    //     else if(s[i] == ')'){
    //         return solve(s,i+1,val-1);
    //     }
    //     else{
    //         return ( solve(s,i+1,val) || solve(s,i+1,val+1) || solve(s,i+1,val-1) );
    //     }
    // }


    // bool checkValidString(string s) {
    //     if(s.size() == 1){
    //         if(s[0] == ')'){
    //             return true;
    //         }
    //         else{
    //             return false;
    //         }
    //     }        

    //     return solve(s,0,0);

    // }

//approach 2: dp memoization

    bool solve(string s,int i,int val,vector<vector<int>>& dp){
        if(i >= s.size()){
            if(val == 0){
                return true;
            }
            else{
                return false;
            }
        }
        if(val < 0){
            return false;
        }

        if(dp[i][val] != -1){
            return dp[i][val];
        }

        if(s[i] == '('){
            return dp[i][val] = solve(s,i+1,val+1,dp);
        }
        else if(s[i] == ')'){
            return dp[i][val] = solve(s,i+1,val-1,dp);
        }
        else{
            return dp[i][val] = (solve(s,i+1,val,dp) || solve(s,i+1,val+1,dp) || solve(s,i+1,val-1,dp));
        }
    }


    bool checkValidString(string s) {
        // if(s.size() == 1){
        //     if(s[0] == '('){
        //         return true;
        //     }
        //     else{
        //         return false;
        //     }
        // }        
        vector<vector<int>> dp(s.size(),vector<int>(s.size(),-1));
        return solve(s,0,0,dp);

    }
};