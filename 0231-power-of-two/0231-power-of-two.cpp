class Solution {
public:
    bool isPowerOfTwo(int n) {
    //brute force
        // int ans=1;
        // if(n==1){
        //     return true;
        // }
        // else{
        //     for(int i=1;i<31;i++){
        //         ans = ans*2;
        //         if(ans == n){
        //             return true;
        //         }
        //     }
        // }

        // return false;

    //optimised by dividing 
        // if(n == 1){
        //     return true;
        // }

        // else{
        //     while(n > 0){
        //         if(n == 1){
        //             return true;
        //         }
        //         if( n % 2 != 0 ){
        //             break;
        //         }

        //         n = n/2;
        //     }
        // }
        // return false;  

    //bit manipulation
        if(n == 0){
            return false;
        }

        int i = 0;
        while(n != 0){
            if((n & 1) == 1){
                i++;
            }

            if( i > 1){
                return false;
            }

            n = n >> 1;
        }
        return true;
    }
};