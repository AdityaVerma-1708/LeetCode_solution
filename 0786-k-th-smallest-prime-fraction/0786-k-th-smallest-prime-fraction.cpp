class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
    //its a very good question
        double left = 0;
        double right = 1;
        double mid;
        vector<int> ans;

        while(left<=right){
            mid = (left + right)/2;
            int num = 0;
            int deno = 0;
            int total = 0;
            int j = 1;
            double maxfreq = 0;
            //function which will return num and deno
            for(int i = 0;i<arr.size();i++){
                while(j<arr.size() && arr[i] >= arr[j]*mid){
                    j++;
                }

                total = total + arr.size() - j;
                if(j<arr.size() && maxfreq < arr[i] * 1.0/arr[i]){
                    maxfreq = arr[i] * 1.0 /arr[j];
                    num = i;
                    deno = j;
                }
            }

            if(total == k){
                ans = {arr[num],arr[deno]};
                break;
            }
            else if(total > k){
                right = mid;
            }
            else{
                left = mid;
            }
        }
        return ans;
    }
};