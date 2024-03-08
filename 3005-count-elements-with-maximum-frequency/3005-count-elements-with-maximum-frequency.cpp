class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
    //approach 1: my brute force using space
        // map<int,int> map;
        // for(int i = 0;i < nums.size();i++){
        //     map[nums[i]] = map[nums[i]] + 1;
        // }

        // //find max 
        // int maxi = -1;
        // for(auto val : map){
        //     maxi = max(maxi,val.second);
        // }

        // int ans = 0;
        // for(auto val : map){
        //     if(val.second == maxi){
        //         ans = ans + val.second;
        //     }
        // }

        // return ans;


    //appraoch 2: without space but more time
        int ans = 0;
        int maxip = 0;
        int maxic = 0;
        sort(nums.begin(),nums.end());

        int i = 0;
        int j = 0;
        while(j<nums.size()){
            if(nums[i] != nums[j]){
                if(maxip < maxic){
                    ans = maxic;
                    maxip = maxic;
                }
                else if(maxip == maxic){
                    ans = ans + maxic;
                }
                i = j;
                maxic = 0;
            }
            else{
                maxic++;
                j++;
            }
        }

        if(maxip < maxic){
            ans = maxic;
        }
        else if(maxip == maxic){
            ans = ans + maxic;
        }
        return ans;
    }
};