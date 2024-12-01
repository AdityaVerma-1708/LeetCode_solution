class Solution {
public:
//APPROACH 1: burte force

    // bool checkIfExist(vector<int>& arr) {
    //     for(int i = 0;i<arr.size();i++){
    //         for(int j = 0;j<arr.size();j++){
    //             if(arr[i] == 2*arr[j] && i != j){
    //                 return true;
    //             }
    //         }
    //     }
    //     return false;
    // }

//approach 2: little optimised

    bool checkIfExist(vector<int>& arr) {
        // unordered_map<int,int> map;  //we can use set also same time complexity
        set<int> set;
        for(int i = 0;i<arr.size();i++){
            if(set.empty()){
                set.insert(arr[i]);
            }
            else{
                if(arr[i]%2 == 0){
                    if(set.find(arr[i]/2) != set.end()){
                        return true;
                    }
                }
                else{
                    if(set.find(arr[i]*2) != set.end()){
                        return true;
                    }
                }
            }
        }
        return false;
    }
};