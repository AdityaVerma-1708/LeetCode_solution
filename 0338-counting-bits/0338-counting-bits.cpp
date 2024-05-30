class Solution {
public:

//appraoch 1:
    // int find(int n){
    //     int ans = 0;
    //     while(n!=0){
    //         if(n & 1 != 0){
    //             ans++;
    //         }
    //         n = n  >> 1;
    //     }
    //     return ans;
    // }

    // vector<int> countBits(int n) {
    //     vector<int> ans ;
    //     for(int i = 0;i<=n;i++){
    //         ans.push_back(find(i));
    //     }
    //     return ans;
    // }

//appraoch 2:
    vector<int> countBits(int n){
        //bascially we can use the previous ans to find the bigger one
        vector<int> ans(n+1);
        ans[0] = 0;
        for(int i = 1;i<=n;i++){
            if(i%2 == 0){
                //even;
                ans[i] = ans[i>>1] ;
            }
            else{
                //odd
                ans[i] = ans[i>>1] + 1;
            }
        }

        return ans;
    }    
};