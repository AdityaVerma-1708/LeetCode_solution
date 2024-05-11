class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
    //approach 1:
        // sort(nums.begin(),nums.end());
        // return nums[nums.size() - k];

    //approach 2: using priority
        priority_queue<int> pq;
        for(int i = 0;i<nums.size();i++){
            pq.push(nums[i]);
        }

        for(int i = 1;i<k;i++){
            pq.pop();
        }

        return pq.top();
    }
};