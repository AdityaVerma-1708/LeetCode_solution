class Solution {
public:
    int kthGrammar(int n, int k) {
    //using recurrsion
        if(n == 1){
            return 0;
        }

        if( k > (pow(2,n-1)/2)){
            int knew = kthGrammar(n-1,k - (pow(2,n-1)/2));
            if(knew == 0){
                return 1;
            }
            else{
                return 0;
            }
        }
        else{
            return kthGrammar(n-1,k);
        }
    }
};