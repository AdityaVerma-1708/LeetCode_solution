class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    //appraoch 1: TLE at 37
        // vector<int> ans;
        // int i = 0;
        // int j = k - 1;
        
        // while(j < nums.size()){
        //     priority_queue<int> q;
        //     for(int m = i;m<=j;m++){
        //         q.push(nums[m]);
        //     }

        //     ans.push_back(q.top());
        //     j++;
        //     i++;
        // }

        // return ans;

    //approach 2: TLE at 37 

        // vector<int> ans;
        // deque<int> dq   ;
        // int i = 0;
        // int j = k - 1;
        
        // int maxi = INT_MIN;
        // for(int m = i;m<=j;m++){
        //     dq.push_back(nums[m]);
        //     maxi = max(maxi,nums[m]);
        // }

        // while(j<nums.size()){
        //     ans.push_back(maxi);

        //     dq.pop_front();
        //     i++;
        //     j++;
        //     if(j < nums.size()){
        //         dq.push_back(nums[j]);
        //         maxi = INT_MIN;
        //         for(int m = i;m<=j;m++){
        //             maxi = max(maxi,nums[m]);
        //         }
        //     }
        // }
        // return ans;  
    
    //approachh 3:
        vector<int> ans;
        deque<int> dq ;
        int i = 0;
        int j = k - 1;
        
        int maxi = INT_MIN;
        int index = 0;
        for(int m = i;m<=j;m++){
            dq.push_back(nums[m]);
            if(maxi < nums[m]){
                maxi = nums[m];
                index = m;
            }
        }

        while(j<nums.size()){
            ans.push_back(maxi);

            if(nums[i] == maxi){
                dq.pop_front();
                i++;
                j++;
                if(j < nums.size()){
                    dq.push_back(nums[j]);
                    maxi = INT_MIN;
                    for(int m = i;m<=j;m++){
                        if(maxi < nums[m]){
                            maxi = nums[m];
                            index = m;
                        }
                    }
                }
            }
            else{
                dq.pop_front();
                i++;
                j++;
                if(j < nums.size() && nums[j] >= maxi){
                    maxi = nums[j];
                    index = j;
                }
                if(j< nums.size()){
                    dq.push_back(nums[j]);
                }
            }
        }
        return ans;
    }
};