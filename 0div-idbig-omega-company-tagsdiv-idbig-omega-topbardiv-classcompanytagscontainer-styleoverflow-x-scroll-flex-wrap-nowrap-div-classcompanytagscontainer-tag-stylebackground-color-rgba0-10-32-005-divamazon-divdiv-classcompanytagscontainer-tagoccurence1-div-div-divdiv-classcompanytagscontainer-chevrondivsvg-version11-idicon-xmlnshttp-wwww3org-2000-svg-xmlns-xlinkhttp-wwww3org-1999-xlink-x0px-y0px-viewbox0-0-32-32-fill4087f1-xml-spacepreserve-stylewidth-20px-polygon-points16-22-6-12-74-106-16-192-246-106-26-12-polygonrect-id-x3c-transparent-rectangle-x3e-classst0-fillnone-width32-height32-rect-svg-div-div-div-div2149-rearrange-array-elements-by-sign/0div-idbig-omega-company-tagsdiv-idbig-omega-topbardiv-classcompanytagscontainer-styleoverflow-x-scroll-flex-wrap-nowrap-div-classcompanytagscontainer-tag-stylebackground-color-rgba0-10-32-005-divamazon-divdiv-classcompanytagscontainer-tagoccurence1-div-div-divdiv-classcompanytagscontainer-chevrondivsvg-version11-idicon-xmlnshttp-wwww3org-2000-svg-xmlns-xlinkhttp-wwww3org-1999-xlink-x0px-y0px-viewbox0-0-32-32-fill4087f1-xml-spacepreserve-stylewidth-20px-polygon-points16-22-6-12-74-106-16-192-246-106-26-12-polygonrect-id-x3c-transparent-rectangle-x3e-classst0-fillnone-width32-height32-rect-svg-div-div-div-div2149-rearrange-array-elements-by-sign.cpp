class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
    //approach 1:
        queue<int> pos,neg;
        for(auto val : nums){
            if(val > 0){
                pos.push(val);
            }
            else{
                neg.push(val);
            }
        }

        int flag = 0;
        for(int i = 0;i< nums.size();i++){
            if(flag == 0){
                nums[i] = pos.front();
                pos.pop();
                flag = 1;
            }
            else{
                nums[i] = neg.front();
                neg.pop();
                flag = 0;
            }
        }

        return nums;
    }
};