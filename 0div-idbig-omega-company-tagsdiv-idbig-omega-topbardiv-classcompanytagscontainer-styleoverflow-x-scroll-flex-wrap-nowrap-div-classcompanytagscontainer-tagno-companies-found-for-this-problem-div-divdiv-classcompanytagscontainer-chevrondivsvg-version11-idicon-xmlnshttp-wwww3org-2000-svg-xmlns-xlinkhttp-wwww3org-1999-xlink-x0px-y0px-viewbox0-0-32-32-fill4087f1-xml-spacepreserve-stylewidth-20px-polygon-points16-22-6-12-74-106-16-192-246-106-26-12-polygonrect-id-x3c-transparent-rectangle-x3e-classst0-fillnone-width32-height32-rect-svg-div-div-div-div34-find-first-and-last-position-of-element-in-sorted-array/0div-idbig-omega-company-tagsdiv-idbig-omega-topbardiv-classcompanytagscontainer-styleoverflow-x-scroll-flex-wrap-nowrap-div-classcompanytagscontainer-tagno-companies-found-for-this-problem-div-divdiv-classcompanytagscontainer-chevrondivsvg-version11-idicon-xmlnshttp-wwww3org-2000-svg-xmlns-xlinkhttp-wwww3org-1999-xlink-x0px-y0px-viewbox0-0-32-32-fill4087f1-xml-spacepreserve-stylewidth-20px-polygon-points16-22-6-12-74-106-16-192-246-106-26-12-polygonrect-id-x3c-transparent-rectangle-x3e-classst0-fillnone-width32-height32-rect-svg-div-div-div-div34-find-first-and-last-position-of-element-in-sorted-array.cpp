class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
    //approrach 1: sliding window   
        // vector<int> ans;
        // if(nums.size() == 0){
        //     ans.push_back(-1);
        //     ans.push_back(-1);
        // }
        // else{
        //     int i = 0;
        //     int j = nums.size()-1;
        //     while(i<=j){
        //         if(nums[i] == target && nums[j] == target){
        //             ans.push_back(i);
        //             ans.push_back(j);
        //             break;
        //         }
        //         if(nums[i] != target){
        //             i++;
        //         }
        //         if(nums[j] != target){
        //             j--;
        //         }
        //     }
        //     if(ans.size() == 0){
        //         ans.push_back(-1);
        //         ans.push_back(-1);
        //     }
        // }
        // return ans;

    //aproach 2: using BS
        vector<int> ans;
        if(nums.size() == 0){
            ans.push_back(-1);
            ans.push_back(-1);
        }
        else{
            int i = 0;
            int j = nums.size()-1;
            if(nums[i] == nums[j] && nums[i] == target){
                ans.push_back(i);
                ans.push_back(j);
                return ans;
            }
            else if (nums[i] == nums[j] && nums[i] != target){
                ans.push_back(-1);
                ans.push_back(-1);
                return ans;
            }
            else{
                while(i<=j){
                    int mid = (i+j)/2;
                    if(nums[mid] > target){
                        j = mid - 1;
                    }
                    else if(nums[mid] < target){
                        i = mid + 1;
                    }
                    else{ //nums[mid] == target
                        if(nums[i] != target && nums[j] == target){
                            i++;
                        }
                        else if(nums[j] != target && nums[i] == target){
                            j--;
                        }
                        else if(nums[i] != target && nums[j] != target){
                            i++;
                            j--;
                        }
                        else{
                            ans.push_back(i);
                            ans.push_back(j);
                            break;
                        }
                    }
                }
                if(ans.size() == 0){
                    ans.push_back(-1);
                    ans.push_back(-1);
                }
            }
        }
        return ans;
    }
};