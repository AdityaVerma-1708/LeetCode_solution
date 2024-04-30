class Solution {
public:
    void nextPermutation(vector<int>& nums) {   
    //approach 1: generating all possible permutation and than telling the next 
    //approach 2: using the inbuilt stl function for next permution 
    
    //approach 3: implementation of stl function 
        //find the breaking point
        int ind = -1;
        for(int i = nums.size()-2;i>=0;i--){
            if(nums[i] < nums[i+1]){
                ind = i;
                break;
            }
        }

        if(ind == -1){
            //ans is reverse of current array
            reverse(nums.begin(),nums.end());
        }
        else{
            //find the one number from back which is just greater than nums[ind]
            for(int i = nums.size()-1;i>ind;i--){
                if(nums[ind] < nums[i]){
                    swap(nums[ind],nums[i]);
                    break;
                }
            }

            //make the reverse number after ind
            int i = ind+1;
            int j = nums.size()-1;
            while(i<j){
                swap(nums[i],nums[j]);
                i++;
                j--;
            }
        }
    }
};