class Solution {
public:
    int singleNumber(vector<int>& nums) {
    //approach 1:   
        // map<int ,int > map;  //we are using the map here first as number in vector second as count
        // for(auto v : nums){
        //     map[v] = map[v] + 1; //for each number it will check in the map anmd update it with its previous value
        // }                         //since m[v] is old second element of pair if it is present it will add 1 to it   
        // for(auto pr : map){
        //     if(pr.second == 1){   //checking the key whose second it 1
        //         return pr.first;  //and returning the key of it
        //     }
        // }
        // return 0;

    //appraoch 2:
        sort(nums.begin(),nums.end());
        int ans = nums[0];
        for(int i = 1;i<nums.size();i++){
            ans = ans ^ nums[i];
        }

        return ans;

    }
};