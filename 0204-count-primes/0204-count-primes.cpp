class Solution {
public:
//approch 1: brute force (TLE)
    // bool checkprime(int a){
    //     for(int i=2;i<a;i++){
    //         if(a%i == 0){
    //             return false;
    //         }
    //     }
    //     return true;
    // }
    // int countPrimes(int n) {
    // 
    //     int count=0;
    //     for(int i=2;i<n;i++){
    //         if(checkprime(i)){
    //             count++;
    //         }
    //     }
    //     return count;

//approch 2: Seive of Eratosthenes Algorithm
    int countPrimes(int n){
        int count = 0;
        vector<bool> prime(n+1,true); //array of size n+1 with all marked as true

        //since 0,1 we not consider 
        prime[0] = false;
        prime[1] = false;

        for(int i=2;i<n;i++){
            if(prime[i]){
                count++;
                for(int j=2*i; j<n; j=j+i){ //marking all number as false which are 
                    prime[j] = false; // coming in the table of i;
                }
            }
        }
        return count;
    }    
    
};