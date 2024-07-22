class Solution {
public:

    // void solve(vector<vector<int>>& ans,int n,vector<int> temp){
    //     if(n == 1){
    //         temp.push_back(1);
    //         ans.push_back(temp);
    //         return ;
    //     }

    //     solve(ans,n-1,temp);

    //     vector<int> temp2 = ans.back();
    //     int i = 0;
    //     while(i <= temp2.size()){
    //         if(i == 0 || i == temp2.size()){
    //             temp.push_back(1);
    //             i++;
    //         }
    //         else{
    //             temp.push_back(temp2[i] + temp2[i-1]);
    //             i++;
    //         }
    //     }
    //     ans.push_back(temp);
    //     return;
    // }
    // vector<vector<int>> generate(int numRows) {
    // //approach 1: recursion
    //     vector<vector<int> >ans;
    //     vector<int>temp;
    //     solve(ans,numRows,temp);
    //     return ans;
    // }

    // practice

    void solve(vector<vector<int>>& ans,int n,vector<int> temp,int i){
        if(i > n){
            return;
        }

        if(i == 1){
            temp.push_back(1);
            ans.push_back(temp);
            temp.clear();
            solve(ans,n,temp,i+1);
        }
        else{
            vector<int> temp2 = ans.back();
            int j = 0;
            while(j <= temp2.size()){
                if(j == 0 || j == temp2.size()){
                    temp.push_back(1);
                    j++;
                }
                else{
                    temp.push_back(temp2[j] + temp2[j-1]);
                    j++;
                }
            }

            ans.push_back(temp);
            temp.clear();
            solve(ans,n,temp,i+1);
        }
    }

    vector<vector<int>> generate(int numRows){
        vector<vector<int>> ans;
        vector<int> temp;

        solve(ans,numRows,temp,1);

        return ans;
    }
};