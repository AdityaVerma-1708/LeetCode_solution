class Solution {
public:

    void solve(vector<string> &ans,string &temp,string s,int i){
        if(i >= s.size()){
            ans.push_back(temp);
            return ;
        }

        if(isdigit(s[i])){
            temp.push_back(s[i]);
            solve(ans,temp,s,i+1);

            temp.pop_back();
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

    //this question taught us alot 
    /* see there are two things first if we pass the reference of temp, then we need to add 
    pop statement in the digit waali if statementm, and in case of pass by value we dont need 
    to add pop statement 

    and for else block irrespective of reference we need to keep the pop statement since in that
    block or in that recurrsive call we pushed the char that we need to pop*/
};