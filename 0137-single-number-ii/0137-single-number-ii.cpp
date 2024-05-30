class Solution {
public:
    int singleNumber(vector<int>& nums) {
    //approach 1: using map;
        map<int,int> map;
        for(int i = 0;i< nums.size();i++){
            map[nums[i]]++;
        }

        for(auto val : map){
            if(val.second == 1){
                return val.first;
            }
        }
        return 0;
    }
};