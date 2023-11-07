class Solution {
public:
    int fib(int n) {
    //appoch 1: brute force (recurssion)    
        // if(n==0 || n==1){
        //     return n;
        // }
        // else{
        //     return fib(n-1) + fib(n-2);
        // }

    //approch 2: for loop
        if(n==0 || n==1){
            return n;
        }
        
        else{
            int prev = 0;
            int curr = 1;
            for(int i=2;i<=n;i++){
                curr = curr + prev;
                prev = curr - prev;
            }
            return curr;
        }
        
    }
};