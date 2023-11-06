class Solution {
public:
    int findTheWinner(int n, int k) {
        vector<int> nums;
        for(int i=0;i<n;i++){
            nums.push_back(i+1);
        }
        int pos=0;

        while(nums.size()>1){
            for(int j=1;j<k;j++){
                pos = (pos + 1)%nums.size();
            }
            nums.erase(nums.begin() + pos);  
        }
        return nums.back();
    }
};