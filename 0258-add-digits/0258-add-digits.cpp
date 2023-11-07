class Solution {
public:
    int addDigits(int num) {
    //approch 1: recurrsion TLE
        if(num<10){
            return num;
        }
        else{
            int n=0;
            while(num > 0){
                n = n + num%10;
                num = num/10;
            }
            return addDigits(n);
        }
    //approch 2:
        // if(num < 10){
        //     return num;
        // }
        // else{
        //     while(num > 10){
        //         int n = 0 ;
        //         while(num != 0){
        //             n = n*10 + num%10;
        //             num = num/10;
        //         }
        //         num = n;
        //     }
        //     return num;     
        // }
    }
};