class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
    //approch 1: wrong ans for case 6 and 7 
        // int ans = INT_MIN;
        // map<int,int> map;
        // sort(nums.begin(),nums.end());

        // int i = nums.size()-1;
        // while(i>=0){
        //     int count=1;
        //     int f = k;
        //     int j = i-1; 
        //     while(j>=0){
        //         if(nums[j] == nums[i]){
        //             j--;
        //             count++;
        //         }
        //         else if(abs(nums[j] - nums[i]) > f){
        //             break;
        //         }
        //         else if(abs(nums[j] - nums[i]) == f){
        //             count++;
        //             f = f - abs(nums[j] - nums[i]);
        //             j--;
        //         }
        //         else if(abs(nums[j] - nums[i]) < f){
        //             count++;
        //             f = f - abs(nums[j] - nums[i]);
        //             j--;
        //         }
                
        //     }
        //     map[nums[i]] = count;        
        //     i--;
        // } 
        // for(auto val : map){
        //     if(val.second > ans){
        //         ans = val.second;
        //     }
        // }
        // return ans;

    //approach 2: TLE --> O(n2)
        // int ans = 0;
        // sort(nums.begin(),nums.end());
        // for(int i = nums.size()-1;i>=0;i--){
        //     int count = 1;
        //     int temp = k;
        //     for(int j = i-1;j>=0;j--){
        //         if(nums[i] - nums[j] > temp){
        //             ans = max(ans,count);
        //             break;
        //         }
        //         else{
        //             temp = temp - (nums[i] - nums[j]);
        //             count++;
        //         }
        //     }
        //     ans = max(ans,count);
        // }
        // return ans;
        
    //appraoch 3:   TLE  64 tc out of 73
        // int j = nums.size()-1;
        // int i = j - 1;
        // int ans = 0;
        // int postfixdiff = 0;
        // int temp = k;
        // sort(nums.begin(),nums.end());
        // while(i >= 0){
        //     postfixdiff = postfixdiff + nums[i+1] - nums[i];
        //     temp = temp - postfixdiff;
        //     if(temp < 0){
        //         ans = max(ans,j - i);
        //         j--;
        //         i = j - 1;
        //         postfixdiff = 0;
        //         temp = k;
        //     }
        //     else{
        //         i--;
        //     }
        // }
        // ans = max(ans,j -i);
        // return ans;      

    //approach 4: 
        int j = nums.size()-1;
        int i = j - 1;
        int ans = 0;
        int postfixdiff = 0;
        int temp = k;
        sort(nums.begin(),nums.end());
        while(i >= 0){
            postfixdiff = postfixdiff + nums[i+1] - nums[i];
            temp = temp - postfixdiff;
            if(temp < 0){
                ans = max(ans,j - i);
                j--;
                i = j - 1;
                postfixdiff = 0;
                temp = k;

                if(ans > j){
                    break;
                }

            }
            else{
                i--;
            }
        }
        ans = max(ans,j -i);
        return ans;    

    }
};