class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
    //approch 1:    
        if(nums.size() == 0){
            return 1;
        }
        else if(nums.size() == 1){
            if(nums[0] <= 0 || nums[0] > 1){
                return 1;
            }
            else if(nums[0] == 1){  
                return 2;
            }
        }
        else{
            sort(nums.begin(),nums.end());
            if(nums[0] > 1 || nums.back() < 0){
                return 1;
            }
            else if(nums[0] < 0 && nums.back() > 0){
                int i = 0;
                while(nums[i] < 1){
                    i++;
                }
                int j = 1;
                for(int k = i;k<nums.size();k++){
                    if(nums[k] == j){
                        j++;
                    }
                    else if(nums[k] == j-1){
                        continue;
                    }
                    else{
                        return j;
                    }
                }
            }
            else if(nums[0] > 0){
                if(nums[0] == 1){
                    int i = 0;
                    int j = 1;
                    for(int i = 0;i<nums.size();i++){
                        if(j == nums[i]){
                            j++;
                        }
                        else if(nums[i] == j-1){
                            continue;
                        }
                        else{
                            return j;
                        }
                    }
                }
            }
            else{  // first number is zero
                int i = 0;
                int j = 0;
                for(int i = 0;i<nums.size();i++){
                    if(j == nums[i]){
                        j++;
                    }
                    else if(nums[i] == j-1){
                        continue;
                    }
                    else{
                        return j;
                    }
                }
            }
        }
        //if flow of program comes here, it means array has every element 
        //so we have to return the next greatest to last;
        return (nums.back()+1);   
    }
};