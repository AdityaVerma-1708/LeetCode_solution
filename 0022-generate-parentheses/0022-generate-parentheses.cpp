class Solution {
public:

    void solve(vector<string>& ans, string &temp, int open,int close){
        if(open == 0 && close == 0){
            ans.push_back(temp);
            return;
        }

        //open
        if(open != 0){
            temp.push_back('(');
            solve(ans,temp,open-1,close);
            temp.pop_back();
        }

        //close  
        /*we have to add the closing only when the number of open present in temp is greater then 
        number of close in temp,
        if the number of close is less in temp then there will be more close present in our pocket
        therefore here i wrote close > open ,since we are taking close and open as a count of open 
        and closing brackets present in our pocket that need to be added 
        
        if we are taking open and close as a count present in temp than we should use open > close
        because of the obvious reasons
        */

        if(close > open){
            temp.push_back(')');
            solve(ans,temp,open,close-1);
            temp.pop_back();
        }
    }

    vector<string> generateParenthesis(int n) {
    //recurrsion
        vector<string > ans;
        string temp = "";
        int open = n-1;
        int close = n;

        temp.push_back('(');

        solve(ans,temp,open,close);
        return ans;
    }
};