class Solution {
public:
    // int findTheWinner(int n, int k) {
    //approch 1:  TC ~ o(n*n) + o(n)
        // vector<int> nums;
        // for(int i=0;i<n;i++){
        //     nums.push_back(i+1);
        // }
        // int pos=0;

        // while(nums.size()>1){
        //     for(int j=1;j<k;j++){
        //         pos = (pos+1)%nums.size();
        //     }
        //     nums.erase(nums.begin() + pos);  
        // }
        // return nums.back();

    //approch 2 : o(n) + o(n)
        // vector<int> nums;
        // for(int i=0;i<n;i++){
        //     nums.push_back(i+1);
        // }   
        // int pos = 0;
        // while(nums.size() > 1){
        //     pos = (pos + k - 1) % nums.size();
        //     nums.erase(nums.begin() + pos);
        // } 
        // return nums.back();

    //approch 3: recursion

    int solve(vector<int> nums,int k,int pos){
        if(nums.size()==1){
            return nums.back();
        }
        else{
            pos = (pos + k - 1)%nums.size();
            nums.erase(nums.begin() + pos);
            return solve(nums,k,pos);
        }
    }

    int findTheWinner(int n, int k) {
        vector<int> nums;
        for(int i=0;i<n;i++){
            nums.push_back(i+1);
        }
        return solve(nums,k,0);
    }
};