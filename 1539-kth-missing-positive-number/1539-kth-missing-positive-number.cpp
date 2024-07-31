class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
    //appraoch 1:
        // int ans = -1;
        // int count = 0;
        // int num = 1;
        // int i = 0;
        // while(i<arr.size()){
        //     if(arr[i] == num){
        //         i++;
        //         num++;
        //     }
        //     else{
        //         count++;
        //         if(count == k){
        //             ans = num;
        //             break;
        //         }
        //         num++;
        //     }
        // }
        // if(ans == -1 ){
        //     return arr.back() + k - count;
        // }

        // return ans;

    //approach 2: 

    //basically first i started from back and exploring 
    /*in the position of 11 it should be 5 if nonn of missing so there will be 11 - 5 missing 
    number behind 11 then we are checking it with k and moving accordingly
    
    at the end we need range of two indices where the missing number should be present*/

        if(k < arr[0]){
            return k;
        }
        if(k > arr[arr.size()-1] - arr.size()){
            return k + arr.size();
        }

        int i = 0;
        int j = arr.size()-1;
        int leftnear = i;
        int rightnear = j;

        while(i<=j){
            int mid = (i+j)/2;
            if(arr[mid] - (mid+1) < k){
                leftnear = mid;
                i = mid + 1;
            }
            else{
                rightnear = mid;
                j = mid - 1;
            }
        }
        return arr[leftnear] + (k - (arr[leftnear] - (leftnear + 1))) ;
    }
};