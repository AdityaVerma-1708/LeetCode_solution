class Solution {
public:
    int numberOfSteps(int num) {
    //brute force:
        int i = 0;
        while(num != 0){
            if(num%2 == 0){
                num = num/2;
            }
            else{
                num = num - 1;
            }
            i++;
        }
        return i;
    }
};