class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
    //using space
        map<int,int> map;
        for(int i = 0;i < nums.size();i++){
            map[nums[i]] = map[nums[i]] + 1;
        }

        //find max 
        int maxi = -1;
        for(auto val : map){
            maxi = max(maxi,val.second);
        }

        int ans = 0;
        for(auto val : map){
            if(val.second == maxi){
                ans = ans + val.second;
            }
        }

        return ans;
    }
};