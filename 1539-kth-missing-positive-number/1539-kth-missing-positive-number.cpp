class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
    //appraoch 1:
        int ans = -1;
        int count = 0;
        int num = 1;
        int i = 0;
        while(i<arr.size()){
            if(arr[i] == num){
                i++;
                num++;
            }
            else{
                count++;
                if(count == k){
                    ans = num;
                    break;
                }
                num++;
            }
        }
        if(ans == -1){
            return arr.back() + k;
        }
        return ans;
    }
};