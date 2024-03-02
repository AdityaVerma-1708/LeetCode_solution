class Solution {
public:

    void solve(vector<string> &ans,string temp,string s,int i){
        if(i >= s.size()){
            ans.push_back(temp);
            return ;
        }

        if(isdigit(s[i])){
            temp.push_back(s[i]);
            solve(ans,temp,s,i+1);

            // temp.pop_back();
        }
        else{
            //uppercase
            temp.push_back(toupper(s[i]));
            solve(ans,temp,s,i+1);
            temp.pop_back();


            //lowercase
            temp.push_back(tolower(s[i]));
            solve(ans,temp,s,i+1);
            temp.pop_back();
        }
    }

    vector<string> letterCasePermutation(string s) {
    //using recurrsion
        vector<string> ans;
        string temp = "";
        solve(ans,temp,s,0);
        return ans;
    }
};