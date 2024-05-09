class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
    //brute force:  TLE
        // long long ans = 0;
        // vector<int> visited(happiness.size(),0);
        // sort(happiness.begin(),happiness.end());
        // int j = happiness.size()-1;

        // while(k > 0){
        //     ans = ans + happiness[j];
        //     visited[j] = 1;
        //     for(int i = 0;i<happiness.size();i++){
        //         if(visited[i] == 0){
        //             happiness[i]--;
        //             if(happiness[i] < 0){
        //                 happiness[i] = 0;
        //             }
        //         }
        //     }
        //     k--;
        //     j--;
        // }
        // return ans;


        
    //little optimize

        long long ans = 0;
        vector<int> visited(happiness.size(),0);
        sort(happiness.begin(),happiness.end());
        int j = happiness.size()-1;

        while(k > 0){
            ans = ans + happiness[j];
            // visited[j] = 1;
            for(int i = 0;i<j;i++){            
                happiness[i]--;
                if(happiness[i] < 0){
                    happiness[i] = 0;
                }
            }
            k--;
            j--;
        }
        return ans;    
    }
};