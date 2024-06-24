class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
    //appraoch 1:  TLE at 58/61
        // int i = 0;
        // int j = 0;
        // int currmin = INT_MAX;
        // int currmax = INT_MIN;
        // int ans = 0;
        // while(j<nums.size()){
        //     currmax = max(currmax,nums[j]);
        //     currmin = min(currmin,nums[j]);

        //     if(currmax - currmin <= limit){
        //         ans = max(ans,j-i+1);
        //         j++;
        //     }
        //     else{
        //         //currmax - currmin > limit
        //         i++;
        //         currmin = INT_MAX;
        //         currmax = INT_MIN;
        //         for(int k = i;k<=j;k++){
        //             currmax = max(currmax,nums[k]);
        //             currmin = min(currmin,nums[k]);
        //         }
        //     }
        // }
        // return ans;

    //approach 2: little optimized --> tle at 58/61
        // int i = 0;
        // int j = 0;
        // int currmin = INT_MAX;
        // int currmax = INT_MIN;
        // int minindex = 0;
        // int maxindex = 0;
        // int ans = 0;
        // while(j<nums.size()){
        //     // currmax = max(currmax,nums[j]);
        //     // currmin = min(currmin,nums[j]);
        //     if(nums[j] > currmax){
        //         maxindex = j;
        //         currmax = nums[j];
        //     }

        //     if(nums[j] < currmin){
        //         minindex = j;
        //         currmin = nums[j];
        //     }

        //     if(currmax - currmin <= limit){
        //         ans = max(ans,j-i+1);
        //         j++;
        //     }
        //     else{
        //         //currmax - currmin > limit
        //         if(minindex < maxindex){
        //             i = minindex + 1;
        //         }
        //         else{
        //             i = maxindex + 1;
        //         }
        //         currmin = INT_MAX;
        //         currmax = INT_MIN;
        //         for(int k = i;k<=j;k++){
        //             if(nums[k] > currmax){
        //                 maxindex = k;
        //                 currmax = nums[k];
        //             }

        //             if(nums[k] < currmin){
        //                 minindex = k;
        //                 currmin = nums[k];
        //             }
        //         }
        //     }
        // }
        // return ans;

    //approach 2:  wrong ans for 41/61

        //maintainig the min heap and max heap
        // int i = 0;
        // int j = 0;

        // priority_queue<int> maxheap;
        // priority_queue<int,vector<int>,greater<int>> minheap;

        // int ans = 0;

        // while(j < nums.size()){
        //     maxheap.push(nums[j]);
        //     minheap.push(nums[j]);

        //     while(!maxheap.empty() && !minheap.empty() && maxheap.top() - minheap.top() > limit){
        //         if(maxheap.top() == nums[i]){
        //             maxheap.pop();
        //         }
        //         if(minheap.top() == nums[i]){
        //             minheap.pop();
        //         }
        //         i++;
        //     }

        //     ans = max(ans,j - i + 1);
        //     j++;
        // }
        // return ans;

    //approach 2:
        int i = 0;
        int j = 0;
        int ans = 0;
    
        priority_queue<pair<int, int>> maxHeap;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;
    
        while (j < nums.size()) {
            maxHeap.push({nums[j], j});
            minHeap.push({nums[j], j});
        

            while (!maxHeap.empty() && !minHeap.empty() && maxHeap.top().first - minHeap.top().first > limit) {
                i++;

                while (!maxHeap.empty() && maxHeap.top().second < i) {
                    maxHeap.pop();
                }
                while (!minHeap.empty() && minHeap.top().second < i) {
                    minHeap.pop();
                }
            }

            ans = max(ans, j - i + 1);
            j++;
        }
    return ans;    
    }
};