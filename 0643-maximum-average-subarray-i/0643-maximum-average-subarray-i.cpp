class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double ans = INT_MIN;
        int i = 0;
        int j = 0;
        double sum = 0.0;
        while(j < nums.size()){
            if(j - i + 1 <= k){
                sum = sum + (double)nums[j];
                j++;
            }
            else{ 
                ans = max(ans,sum/k);
                sum = sum - (double)nums[i];
                sum = sum + (double)nums[j];
                j++;
                i++;
            }
        }

        ans = max(ans,sum/k);
        return ans;
    }
};