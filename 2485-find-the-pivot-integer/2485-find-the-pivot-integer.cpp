class Solution {
public:
    int pivotInteger(int n) {
    //brute force
        // int total = n*(n+1)/2;
        // int sum = 0;
        // for(int i = 1;i<=n;i++){
        //     sum  = sum + i;
        //     if(sum == (total - sum + i)){
        //         return i;
        //     }
        // }
        // return -1;

    //maths
        int total = n*(n+1)/2;
        double pivot = sqrt(total);

        if(pivot - ceil(pivot) == 0){
            return int(pivot);
        }    
        return -1;
    }
};