class Solution {
public:
    int fib(int n) {
    //appoch 1: brute force (recurssion)    
        if(n==0){
            return 0;
        }
        else if(n==1){
            return 1;
        }
        else{
            return fib(n-1) + fib(n-2);
        }
    }
};