class Solution {
public:
    // int tribonacci(int n) {
    //     if(n == 0){
    //         return 0;
    //     }
    //     else if (n == 1 || n == 2){
    //         return 1;
    //     }
    //     else{
    //         return tribonacci(n-1) + tribonacci(n-2) + tribonacci(n-3); 
    //     }
    // }

    /* n = 0 => 0
       n = 1 => 1
       n = 2 => 1
       n = 3 => ans = 2
       n = 4 => ans = 4
       n = 5 => ans = 7
       n = 6 => ans = 13
       n = 7 => ans = 24
    */
    int tribonacci(int n){
        int arr[38];
        arr[0] = 0;
        arr[1] = 1;
        arr[2] = 1;

        for(int i = 3;i<38;i++){
            arr[i] = arr[i-1] + arr[i-2] + arr[i-3]; 
        }

        return arr[n];
    }
};