class Solution {
public:
    int fib(int n) {
    //appoch 1: brute force (recurssion)    
        if(n==0 || n==1){
            return n;
        }
        else{
            return fib(n-1) + fib(n-2);
        }
    }
};