class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
    //brute force:  
        int ans = 0;
        int i = 0;
        while(tickets[k] != 0){
            if(tickets[i] != 0){
                tickets[i]--;
                ans++;
            }

            i++;
            if(i == tickets.size()){
                i = 0;
            }
        }
        return ans;
    }
};