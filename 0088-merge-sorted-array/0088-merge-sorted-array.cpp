class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    //approch 1:
        // vector<int> ans;
        // int i = 0;
        // int j = 0;
        // while(i < m && j < n){
        //     if(nums1[i] > nums2[j]){
        //         ans.push_back(nums2[j]);
        //         j++;
        //     }
        //     else if(nums1[i] < nums2[j]){
        //         ans.push_back(nums1[i]);
        //         i++;
        //     }
        //     else{
        //         ans.push_back(nums1[i]);
        //         ans.push_back(nums2[j]);
        //         i++;
        //         j++;
        //     }
        // }
        // if(i != m){
        //     while(i<m){
        //         ans.push_back(nums1[i]);
        //         i++;
        //     }
        // }
        // if(j != n){
        //     while(j<n){
        //         ans.push_back(nums2[j]);
        //         j++;
        //     }
        // }
        // nums1 = ans;   

    //approch 2: we should not use extra space
        int j = 0;
        for(int i = m;i<nums1.size();i++){
            nums1[i] = nums2[j];
            j++;
        }
        sort(nums1.begin(),nums1.end());

    }
};