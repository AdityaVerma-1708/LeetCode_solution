class Solution {
public:
    bool threeConsecutiveOdds(vector<int>& arr) {
        if(arr.size() <= 2){
            return false;
        }

        int i = 0;
        int j = 0;
        while( j < arr.size()){
            if(j - i == 3){
                return true;
            }

            if(arr[j] % 2 == 0){
                j++;
                i = j;
            }
            else{
                j++;
            }
            
        }

        if(j-i+1 == 3){
            return true;
        }
        return false;
    }
};