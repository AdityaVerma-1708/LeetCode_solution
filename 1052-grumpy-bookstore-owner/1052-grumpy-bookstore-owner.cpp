class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
    //brute force: wrong ans for 37 tc
        // int ans = 0;
        // int count = 0;
        // int left = 0;
        // int right = 0;
        // int i = 0;
        // int j = 0;
        // while(j < customers.size()){
        //     if(j - i  + 1 <= minutes){
        //         count = count + customers[j];
        //         j++;
        //     }
        //     else{
        //         if(count > ans){
        //             left = i;
        //             right = j-1;
        //             ans = count;
        //         }

        //         count = count - customers[i];
        //         i++;
        //         count = count + customers[j];
        //         j++;
        //     }
        // }

        // if(count > ans){
        //     left = i;
        //     right = j-1;
        //     ans = count;
        // }

        // for(int i = 0;i<grumpy.size();i++){
        //     if((i < left || i > right) && grumpy[i] == 0){
        //         ans = ans + customers[i];
        //     }
        // }
        // return ans;
    
    //approach 2:

        int i = 0;
        int j = 0;
        int count = 0;
        int countmax = 0;

        while(j < grumpy.size()){
            if(j - i + 1 <= minutes){
                if(grumpy[j] == 1){
                    count = count + customers[j];
                }
                j++;
            }
            else{
                countmax = max(countmax,count);
                if(grumpy[i] == 1){
                    count = count - customers[i];
                }
                i++;
                if(grumpy[j] == 1){
                    count = count + customers[j];
                }
                j++;
            }
        }
        countmax = max(countmax,count);

        for(int i = 0;i<customers.size();i++){
            if(grumpy[i] == 0){
                countmax = countmax + customers[i];
            }
        }

        return countmax;
    }
};