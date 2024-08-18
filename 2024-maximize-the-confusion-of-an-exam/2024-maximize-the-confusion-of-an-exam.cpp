class Solution {
public:
    int maxConsecutiveAnswers(string answerKey, int k) {
    //brute force:
        int ans = 0;
        int t = 0;
        int f = 0;

        int i = 0;
        int j = 0;

        while(j < answerKey.size()){
            if(answerKey[j] == 'T'){
                t++;
            }
            else{
                f++;
            }

            if(abs(max(t,f) - (j-i+1)) <= k){

                ans = max(ans,j - i + 1);
                j++;

            }
            else{ //max(t,f) - (j-i+1) > k

                while(abs(max(t,f) - (j - i + 1)) > k){
                    if(answerKey[i] == 'T'){
                        t--;
                    }
                    else{
                        f--;
                    }
                    i++;
                }
                j++;

            }
        }
        return ans;
    }
};