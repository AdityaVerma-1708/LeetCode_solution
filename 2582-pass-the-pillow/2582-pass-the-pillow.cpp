class Solution {
public:
    int passThePillow(int n, int time) {
    //appraoch 1:
        if(time < n){
            return  time + 1;
        }
        else{
            int motion = time/(n-1);
            if(motion%2 == 0){
                //forward
                return 1 + (time  - motion * (n-1));
            }
            else{
                //backward
                return n - (time - motion*(n-1));
            }
        }
    }
};