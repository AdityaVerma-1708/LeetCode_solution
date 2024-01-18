class Solution {
public:

    // void solve(vector<int> &nums){
    //     if(nums.size() == 1){
    //         return ;
    //     }

    //     int num = nums.back();
    //     nums.pop_back();
        
    //     solve(nums);

    //     vector<int> temp;
    //     int i = 0;
    //     while (i < nums.size() && nums[i] < num) {
    //         temp.push_back(nums[i]);
    //         i++;
    //     }

    //     temp.push_back(num);

    //     while (i < nums.size()) {
    //         temp.push_back(nums[i]);
    //         i++;
    //     }
    //     nums = temp;
    //     temp.clear();
    //     return; 
    // }

    // vector<int> sortArray(vector<int>& nums) {
    // //appraoch 1: using recursion :::: TLE for large inputs
    //     solve(nums);
    //     return nums;
    // }

    //--------------------------------------------------------------------------

    // void insertAtCorrect(vector<int>& nums,int num){
    //     if(nums.size() == 0 || nums.back() <= num){
    //         nums.push_back(num);
    //         return ;
    //     }

    //     int temp = nums.back();
    //     nums.pop_back();

    //     insertAtCorrect(nums,num);

    //     nums.push_back(temp);

    //     return;
    // }

    // void solve(vector<int>& nums){
    //     if(nums.size() == 1){
    //         return ;
    //     }

    //     int num = nums.back();
    //     nums.pop_back();

    //     solve(nums);

    //     insertAtCorrect(nums,num);

    //     return;
    // }
    // vector<int> sortArray(vector<int>& nums) {
    //     solve(nums);
    //     return nums;
    // }



    //---------------------------------------------------------------------------

    void merge(vector<int>& nums,int low,int high,int mid){
        if(low >= high){
            return;
        }
        int i = low;
        int j = mid+1;
        vector<int> ans;
        while(i <= mid && j <= high){
            if(nums[i] >= nums[j]){
                ans.push_back(nums[j]);
                j++;
            }
            else{
                ans.push_back(nums[i]);
                i++;
            }
        }

        while(i<=mid){
            ans.push_back(nums[i]);
            i++;
        }
        while(j<=high){
            ans.push_back(nums[j]);
            j++;
        }

        for (int k = 0; k < ans.size(); k++) {
            nums[low + k] = ans[k];
        }
    }

    void mergesort(vector<int>& nums,int s,int e){
        if(s < e){
            int mid =  s + (e - s)/2;
            mergesort(nums,s,mid);
            mergesort(nums,mid+1,e);
            merge(nums,s,e,mid);
        }
    }

    vector<int> sortArray(vector<int>& nums){
    //merge sort
        int start = 0;
        int end = nums.size()-1;
        mergesort(nums,start,end);
        return nums;
    }
};