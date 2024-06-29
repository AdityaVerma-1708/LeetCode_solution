class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
    //approach 1: O(nlogn)

        // if(nums.size() <= 1){
        //     return nums.size();
        // }
        // sort(nums.begin(),nums.end());
        // int i = 0;
        // int j = 1;
        // int ans = 0;
        // int rep = 0;

        // while(j < nums.size()){
        //     if(nums[j] - nums[j-1] == 1){
        //         j++;
        //     }
        //     else if( nums[j] - nums[j-1] == 0){
        //         j++;
        //         rep++;
        //     }
        //     else{
        //         ans = max(ans,j-i-rep);
        //         i = j;
        //         j++;
        //         rep = 0;
        //     }
        // }

        // ans = max(ans,j-i-rep);
        // return ans;


    //appraoch 2: O(n)
        if(nums.size() <= 1){
            return nums.size();
        }

        map<int,int> map;
        for(int i = 0;i<nums.size();i++){
            map[nums[i]]++;
        }

        int ans = 0;
        int prev = INT_MAX;
        int rep = 0;
        int count = 0;
        for(auto val : map){
            if(prev == INT_MAX){
                count++;
                prev = val.first;
                rep = rep + val.second - 1;
            }
            else{
                if(val.first - prev == 1){
                    count++;
                    prev = val.first;
                    rep = rep + val.second - 1;
                }
                else{
                    ans = max(ans,count);
                    prev = val.first;
                    rep = val.second;
                    count = 1;
                }
            }
        }
        ans = max(ans,count);
        return ans;
    }
};