class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
    //approach 1:
        map<int,int> map1;
        map<int,int> map2;

        for(int i = 0;i<nums1.size();i++){
            map1[nums1[i]]++;
        }
        for(int i = 0;i<nums2.size();i++){
            map2[nums2[i]]++;
        }

        vector<int> ans;
        
        auto it1 = map1.begin();
        auto it2 = map2.begin();

        while(it1 != map1.end() && it2 != map2.end()){
            if(it1->first == it2->first){
                int mini = min(it1->second,it2->second);
                for(int i = 0;i<mini;i++){
                    ans.push_back(it1->first);
                }
                it1++;
                it2++;
            }
            else if(it1->first > it2->first){
                it2++;
            }
            else{
                it1++;
            }
        }

        return ans;

    }
};