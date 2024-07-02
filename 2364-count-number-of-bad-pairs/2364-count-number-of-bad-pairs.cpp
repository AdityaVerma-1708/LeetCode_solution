class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
    //brute force: ofcource TLE at 56/65
        // long long ans = 0;
        // for(int i = 0;i<nums.size()-1;i++){
        //     for(int j = i+1;j<nums.size();j++){
        //         if( j-i != nums[j] - nums[i]){
        //             ans++;
        //         }
        //     }
        // }

        // return ans;
    
    //approach 2:
        if(nums.size() == 1){
            return 0;
        }
        map<long long,long long> map;
        for(int i = 0;i<nums.size();i++){
            map[nums[i] - i]++;
        }

        long long good = 0;
        for(auto val : map){
            if(val.second > 1){
                good = good + ( (val.second)*(val.second - 1)/2 );
            }
        }

        long long total = nums.size() * (nums.size() - 1)/2;
        return total - good;
    }
};