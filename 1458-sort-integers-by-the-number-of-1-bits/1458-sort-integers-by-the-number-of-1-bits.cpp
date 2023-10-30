class Solution {
public:

//approch 1:
    // int numberOfOne(int n){
    //     int count = 0;
    //     while(n>0){
    //         if(n%2==1){
    //             count++;
    //         }
    //         n = n/2;
    //     }
    //     return count;
    // }
    // vector<int> sortByBits(vector<int>& arr) {
    //     if(arr.size()<=1){
    //         return arr;
    //     }
    //     else{   
    //         for(int i=0;i<arr.size()-1;i++){   //bubble sort
    //             for(int j=0;j<arr.size()-i-1;j++){
    //                 if(numberOfOne(arr[j]) > numberOfOne(arr[j+1])){
    //                     swap(arr[j],arr[j+1]);
    //                 }
    //                 else if(numberOfOne(arr[j]) == numberOfOne(arr[j+1])){
    //                     if(arr[j]>arr[j+1]){
    //                         swap(arr[j],arr[j+1]);
    //                     }
    //                 }
    //             }
    //         }
    //     }
    //     return arr;
    // }

//aproch 2:
    static int numberOfOne(int n){
        int count=0;
        while(n>0){
            if(n%2==1){
                count++;
            }
            n = n/2;
        }
        return count;
    }

    static bool compareBasis(int a,int b){
        if(numberOfOne(a) < numberOfOne(b)){
            return true;
        }
        else if(numberOfOne(a) == numberOfOne(b)){
            return a<b;
        }
        return false;
    }

    vector<int> sortByBits(vector<int>& arr){
        if(arr.size()<=1){
            return arr;
        }
        else{
            sort(arr.begin(),arr.end(),compareBasis);
        }
        return arr;
    }
};