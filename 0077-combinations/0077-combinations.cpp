class Solution {
public:

    void solve(vector<vector<int>> &ans,vector<int>& temp,int i, int k,int n){
        
        if(temp.size() == k){  
            ans.push_back(temp);
            return;
        }

        for(int j = i;j<=n;j++){
            temp.push_back(j);
            solve(ans,temp,j+1,k,n);
            temp.pop_back();
        }
    }

    vector<vector<int>> combine(int n, int k) {
    //approach 1:
        vector<vector<int>> ans;
        vector<int> temp;
        solve(ans,temp,1,k,n);
        return ans;
    }
};