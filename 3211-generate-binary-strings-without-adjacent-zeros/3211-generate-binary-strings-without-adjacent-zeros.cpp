class Solution {
public:

    void solve(vector<string>& ans,string curr,int n){
        if(curr.size() == n){
            ans.push_back(curr);
            return;
        }

        if(curr.size() > 0 && curr.back() == '0'){
            curr.push_back('1');
            solve(ans,curr,n);
        }
        else{
            curr.push_back('0');
            solve(ans,curr,n);

            curr.pop_back();

            curr.push_back('1');
            solve(ans,curr,n);
        }
    }

    vector<string> validStrings(int n) {
        vector<string> ans;

        string curr = "";
        solve(ans,curr,n);
        return ans;
    }
};