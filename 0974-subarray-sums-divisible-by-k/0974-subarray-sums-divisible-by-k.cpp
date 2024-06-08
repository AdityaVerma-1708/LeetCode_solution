class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
    //approach 1: TLE 69 out of 73
        // int i = 0;
        // int j = 0;
        // int sum = 0;
        // int ans = 0;
        // while(j < nums.size() && i < nums.size()){
        //     sum = sum + nums[j];
            
        //     if(sum % k == 0){
        //         ans++;
        //     }

        //     if(j == nums.size()-1){
        //         i++;
        //         j = i;
        //         sum = 0;
        //     }
        //     else{
        //         j++;
        //     }
        // }

        // return ans;

    //appraoch 2:  wrong ans
        // int ans = 0;
        // int sum = 0;
        // map<int,int> map;
        // map[0] = 1;
        // for(int i = 0;i< nums.size();i++){
        //     sum = sum + nums[i];

        //     if(map.find(abs(sum % k)) == map.end()){
        //         map[abs(sum % k)]++;
        //     }
        //     else{
        //         ans = ans + map[abs(sum % k)];
        //         map[abs(sum % k)]++;
        //     }
        // }

        // return ans;

    //why is it wrong we can not just use abs()..think about it 
        int ans = 0;
        int sum = 0;
        map<int,int> map;
        map[0] = 1;
        for(int i = 0;i< nums.size();i++){
            sum = sum + nums[i];

            int rem = sum % k;
            if(rem < 0){
                rem = rem + k;
            }
            if(map.find(rem) == map.end()){
                map[rem]++;
            }
            else{
                ans = ans + map[rem];
                map[rem]++;
            }
        }

        return ans;    
    }
};