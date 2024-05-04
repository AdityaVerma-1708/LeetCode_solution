class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
    //brute force:  wrong ans cuz forget to consider that only 2 person at a time 
        // sort(people.rbegin(),people.rend());
        // int i = 0;
        // vector<int> done(people.size(),0);
        // int ans = 0;
        // while(i<people.size()){
        //     if(done[i] == 0){
        //         done[i] = 1;
        //         int currsum = people[i];
        //         int j = 0;
        //         ans++;
        //         while(j<people.size()){
        //             if(done[j] == 0){
        //                 if(limit - currsum < people[j]){
        //                     j++;
        //                 }
        //                 else{
        //                     currsum = currsum + people[j];
        //                     done[j] = 1;
        //                     j++;
        //                 }
        //             }
        //             else{
        //                 j++;
        //             }
        //         }
        //     }
        //     i++;
        // }
        // return ans;

    //appproach 2:    //tle at 73 out of 78
        // sort(people.rbegin(),people.rend());
        // vector<int> done(people.size(),0);

        // int ans = 0;
        // int i = 0 ;
        // while(i < people.size()){
        //     if(done[i] == 0){
        //         int currsum = people[i];
        //         ans++;
        //         done[i] = 1;
        //         int j = i + 1;
        //         while(j < people.size()){
        //             if(done[j] == 0){
        //                 if(limit - currsum >= people[j]){
        //                     done[j] = 1;
        //                     break;
        //                 }
        //                 else{
        //                     j++;
        //                 }
        //             }
        //             else{
        //                 j++;
        //             }

        //         }
        //     }
        //     i++;
        // }
        // return ans;

    //approach 3:  only two person at a time help to use 2 pointer approach  

        sort(people.begin(),people.end());
        int ans = 0;
        int i = 0;
        int j = people.size()-1;

        while(i <= j){
            if(people[i] + people[j] <= limit){
                ans++;
                i++;
                j--;
            }
            else{
                ans++;
                j--;
            }
        }

        return ans;
    }
};