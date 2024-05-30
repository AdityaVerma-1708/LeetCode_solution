class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
    //appraoch 1: using map
        // map<int,int> map;
        // vector<int> ans;
        // for(int i = 0;i<nums.size();i++){
        //     map[nums[i]]++;
        // }

        // for(auto val : map){
        //     if(val.second == 1){
        //         ans.push_back(val.first);
        //     }
        // }

        // return ans;

    //appraoch 2: bit manipulation 
        long long xorr = 0;
        for(int i = 0;i<nums.size();i++){
            xorr = xorr ^ nums[i];
        }

        long long rightmost = (xorr & (-xorr));
        int b1 = 0;
        int b2 = 0;
        for(int i = 0;i<nums.size();i++){
            if((nums[i] & rightmost) != 0){
                b1 = b1 ^ nums[i];
            }
            else{
                b2 = b2 ^ nums[i];
            }
        }

        return {b1,b2};

    }
};