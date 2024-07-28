class Solution {
public:

    void merge(vector<int>& nums,int s,int e,int mid){
        vector<int> temp;
        
        int i = s;
        int j = mid + 1;

        while(i <= mid && j <= e){
            if(nums[i] > nums[j]){
                temp.push_back(nums[j]);
                j++;
            }
            else{
                temp.push_back(nums[i]);
                i++;
            }
        }

        while(i<=mid){
            temp.push_back(nums[i]);
            i++;
        }

        while(j<=e){
            temp.push_back(nums[j]);
            j++;
        }

        for(int m = 0;m<temp.size();m++){
            nums[s + m] = temp[m];
        }
    }

    int mergesort(vector<int>& nums,int s,int e){
        int count = 0;
        if(s >= e){
            return count;
        }

        int mid = (s+e)/2;
        count = count + mergesort(nums,s,mid);
        count = count + mergesort(nums,mid+1,e);

        int right = mid + 1;
        for (int i = s; i <= mid; i++) {
            while (right <= e && nums[i] > 2 * nums[right]){
                right++;
            } 
            count = count + (right - (mid + 1));
        }
        merge(nums,s,e,mid);

        return count;
    }

    int reversePairs(vector<int>& nums) {
    //brute force:  
        // int ans = 0;
        // for(int i = 0;i<nums.size();i++){
        //     for(int j = i+1;j<nums.size();j++){
        //         if(nums[i] > (nums[j]*2)){
        //             ans++;
        //         }
        //     }
        // }
        // return ans;

    //approach 2: using merge sort 
        return mergesort(nums,0,nums.size()-1);
    }
};