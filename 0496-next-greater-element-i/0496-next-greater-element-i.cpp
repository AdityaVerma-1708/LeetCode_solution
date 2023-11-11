class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
    //approch 1: tc ~ o(n3)
        // vector<int> ans;
        // for(int i = 0 ;i< nums1.size() ; i++){
        //     int a = nums1[i];
        //     for(int j = 0;j<nums2.size();j++){
        //         if(a == nums2[j]){
        //             int flag = 0;
        //             for(int k = j+1;k<nums2.size();k++){
        //                 if(nums2[k] > a){
        //                     ans.push_back(nums2[k]);
        //                     flag = 1;
        //                     break;
        //                 }   
        //             }
        //             if(flag == 0){
        //                 ans.push_back(-1);
        //             }
        //             flag = 0;
        //         }
        //     }
        // }
        // return ans;

    //approch 2: using map
       //basically we can store the next greatest element in the map
        map<int,int> map;
        int flag = 0;
        for(int i=nums2.size()-1;i>=0;i--){
            for(int j=i+1;j<nums2.size();j++){
                if(nums2[j] > nums2[i]){
                    map[nums2[i]] = nums2[j];
                    flag = 1;
                    break;
                }
            }
            if(flag == 0){
                map[nums2[i]] = -1;
            }
            flag = 0;
        }

        vector<int> ans;
        for(auto val :  nums1){
            if(map.find(val) != map.end()){
                auto iterator = map.find(val);
                ans.push_back(iterator->second);
            }
            else{
                ans.push_back(-1);
            }
        }
        return ans;      
    }
};