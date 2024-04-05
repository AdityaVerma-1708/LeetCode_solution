class Solution {
public:

    void solve(string &ans,string temp,int prevsize ){
        if(ans.size() == prevsize){
            return ;
        }
        temp = ans;

        ans.erase();

        int i = 0;
        while(i < temp.size()){
            if(temp[i] == temp[i+1]){
                ans.push_back(temp[i]);        
                i++;        
            }
            else{ // not equal
                if(toupper(temp[i]) == toupper(temp[i+1])){
                    i = i + 2;
                }
                else{  // not equal
                    ans.push_back(temp[i]);
                    i++;
                }
            }
        }    
        solve(ans,temp,temp.size());
    }

    string makeGood(string s) {
    //brute force

        if(s.size() == 1){
            return s;
        }

        string ans = s;
        solve(ans,s,-1);

        return ans;
    }
};