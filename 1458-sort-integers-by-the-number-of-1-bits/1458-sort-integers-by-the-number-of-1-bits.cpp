class Solution {
public:

    int numberOfOne(int n){
        int count = 0;
        while(n>0){
            if(n%2==1){
                count++;
            }
            n = n/2;
        }
        return count;
    }
    vector<int> sortByBits(vector<int>& arr) {
        if(arr.size()<=1){
            return arr;
        }
        else{   
            for(int i=0;i<arr.size()-1;i++){
                for(int j=0;j<arr.size()-i-1;j++){
                    if(numberOfOne(arr[j]) > numberOfOne(arr[j+1])){
                        swap(arr[j],arr[j+1]);
                    }
                    else if(numberOfOne(arr[j]) == numberOfOne(arr[j+1])){
                        if(arr[j]>arr[j+1]){
                            swap(arr[j],arr[j+1]);
                        }
                    }
                }
            }
        }
        return arr;
    }
};