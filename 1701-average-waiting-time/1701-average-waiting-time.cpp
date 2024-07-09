class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        long long total = customers[0][0] + customers[0][1];
        long long wait = customers[0][1];

        for(int i = 1;i<customers.size();i++){
            if(total > customers[i][0]){
                wait = wait + total - customers[i][0] + customers[i][1];
                total = total + customers[i][1];
            }
            else{
                wait = wait + customers[i][1];
                total = customers[i][0] + customers[i][1];
            }
        }

        return (double)wait/customers.size();
    }

};