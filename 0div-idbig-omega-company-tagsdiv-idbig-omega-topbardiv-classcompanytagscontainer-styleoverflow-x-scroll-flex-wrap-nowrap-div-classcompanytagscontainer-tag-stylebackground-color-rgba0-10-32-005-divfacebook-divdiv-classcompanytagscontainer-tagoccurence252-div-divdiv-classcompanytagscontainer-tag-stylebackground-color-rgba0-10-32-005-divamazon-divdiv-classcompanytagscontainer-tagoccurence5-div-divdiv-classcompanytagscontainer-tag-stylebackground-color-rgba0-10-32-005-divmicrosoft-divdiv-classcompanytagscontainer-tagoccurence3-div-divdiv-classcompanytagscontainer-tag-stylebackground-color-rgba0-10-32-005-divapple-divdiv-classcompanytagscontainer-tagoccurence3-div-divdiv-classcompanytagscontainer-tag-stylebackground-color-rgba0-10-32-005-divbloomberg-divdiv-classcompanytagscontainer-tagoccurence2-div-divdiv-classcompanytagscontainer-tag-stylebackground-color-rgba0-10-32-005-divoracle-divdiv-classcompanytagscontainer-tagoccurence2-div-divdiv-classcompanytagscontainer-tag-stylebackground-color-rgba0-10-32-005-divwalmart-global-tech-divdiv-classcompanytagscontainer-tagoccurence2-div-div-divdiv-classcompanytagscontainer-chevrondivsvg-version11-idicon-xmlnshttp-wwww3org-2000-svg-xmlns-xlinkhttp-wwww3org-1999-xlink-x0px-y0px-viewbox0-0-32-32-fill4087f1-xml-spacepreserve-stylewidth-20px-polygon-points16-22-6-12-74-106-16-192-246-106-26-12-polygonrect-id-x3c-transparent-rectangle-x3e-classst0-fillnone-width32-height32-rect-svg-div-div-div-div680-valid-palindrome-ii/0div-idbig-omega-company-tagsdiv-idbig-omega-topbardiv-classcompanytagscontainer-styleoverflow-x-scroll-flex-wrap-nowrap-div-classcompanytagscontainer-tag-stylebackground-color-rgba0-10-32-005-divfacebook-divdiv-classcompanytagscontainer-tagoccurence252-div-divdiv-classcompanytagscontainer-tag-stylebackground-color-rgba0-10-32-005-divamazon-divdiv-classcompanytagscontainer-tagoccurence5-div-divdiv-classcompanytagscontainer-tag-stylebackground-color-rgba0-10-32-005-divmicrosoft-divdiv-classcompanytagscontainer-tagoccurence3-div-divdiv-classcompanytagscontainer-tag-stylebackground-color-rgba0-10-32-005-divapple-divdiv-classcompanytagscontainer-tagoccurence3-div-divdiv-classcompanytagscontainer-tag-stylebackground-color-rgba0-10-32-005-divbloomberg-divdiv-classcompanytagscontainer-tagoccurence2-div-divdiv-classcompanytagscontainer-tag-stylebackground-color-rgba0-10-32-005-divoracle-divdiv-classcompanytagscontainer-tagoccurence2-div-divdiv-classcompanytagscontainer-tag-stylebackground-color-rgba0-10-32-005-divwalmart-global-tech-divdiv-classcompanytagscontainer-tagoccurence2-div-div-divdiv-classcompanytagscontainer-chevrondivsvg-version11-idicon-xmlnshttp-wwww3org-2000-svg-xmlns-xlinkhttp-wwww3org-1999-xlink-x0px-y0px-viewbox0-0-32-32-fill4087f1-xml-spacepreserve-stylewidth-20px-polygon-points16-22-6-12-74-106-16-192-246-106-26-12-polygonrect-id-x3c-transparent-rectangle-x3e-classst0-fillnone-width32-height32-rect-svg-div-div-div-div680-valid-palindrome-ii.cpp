class Solution {
public:

    bool check(string s,int i,int j){
        while(i<j){
            if(s[i] != s[j]){
                return false;
            }
            i++;
            j--;
        }
        return true;
    }


    bool validPalindrome(string s) {
    //appraoch 1: wrong ans 464 test case

        // if(s.size() <= 2){
        //     return true;
        // }
        // else{
        //     int k = 1;
        //     int i = 0;
        //     int j = s.size()-1;
        //     while(i<j){
        //         if(s[i] == s[j]){
        //             i++;
        //             j--;
        //         }
        //         else{
        //             if(s[i+1] == s[j] && k == 1){
        //                 i++;
        //                 k--;
        //             }
        //             else if (s[i] == s[j-1] && k == 1){
        //                 k--;
        //                 j--;
        //             }
        //             else{
        //                 return false;
        //             }
        //         }
        //     }
        //     return true;
        // }

    //apppraoch 2: modification of prev approach 
        if(s.size() <= 2){
            return true;
        }    
        else{
            int i = 0;
            int j = s.size()-1;
            while(i<j){
                if(s[j] == s[i]){
                    i++;
                    j--;
                }
                else if(s[i] != s[j]){
                    if(check(s,i+1,j)){
                        return true;
                    }
                    else if(check(s,i,j-1)){
                        return true;
                    }
                    return false;
                }
            }
            return true;
        }
    }
};