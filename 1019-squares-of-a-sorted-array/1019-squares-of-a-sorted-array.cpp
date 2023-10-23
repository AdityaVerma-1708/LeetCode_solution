class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
    //approch 1: best method without using any space  just using the sort funciton 
        for(auto &val : nums){
            val = val*val;
        }
        sort(nums.begin(),nums.end());
        return nums;

    //--optimization (without sorting)

        //basically maximum element ya most negative the square hoga ya most positive

        // int i=0;
        // int j=nums.size()-1;
        // list<int> ans;

        // for(int k=nums.size()-1;k>=0;k--){
        //     int a = nums[i]*nums[i];
        //     int b = nums[j]*nums[j];

        //     if(a>b){
        //         ans.push_front(a);
        //         i++;
        //     }
        //     else{
        //         ans.push_front(b);
        //         j--;
        //     }
        // }
        // vector<int> anss(ans.begin(),ans.end());
        // return anss;

        //this is not fully optimize since we have used list and vector both

    //optimization-2
        
         
    }
};