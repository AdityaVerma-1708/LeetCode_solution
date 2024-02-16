class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
    //approach 1:
        map<int,int> map;
        int count = 1;
        for(int i = 0;i<arr.size();i++){
            map[arr[i]] = map[arr[i]] + 1;
        }
        
        vector<int> temp;
        for(auto val : map){
            temp.push_back(val.second);
            count++;
        }

        sort(temp.begin(),temp.end());
        for(int i =0;i<temp.size();i++){
            if(k == temp[i]){
                count--;
                k = 0;
                break;
            }
            else if( k < temp[i]){
                break;
            }
            else{   // k > temp[i]
                k = k - temp[i];
                count--;
            }
        }

        return count-1;
    }
};