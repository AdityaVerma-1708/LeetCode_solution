class Solution {
public:
    bool canBeEqual(string s1, string s2) {
    //approch 1:
        // if(s1.size() != s2.size()){
        //     return false;
        // }
        // else{
        //     int flag = 0 ;
        //     for(int i = 0;i<s1.size();i++){
        //         for(int j = 0;j<s2.size();j++){
        //             if(s1[i] == s2[j]){
        //                 if(abs(j-i)%2 != 0){
        //                     return false;
        //                 }
        //                 flag = 1;
        //             }
        //         }
        //         if(flag == 0){ // we didn't find the element in the s2 
        //             return false;
        //         }
        //         flag = 0;
        //     }
        //     return true;
        // }
    //-- will give an error for the string contaning duplicates char 

    // we should take use of the given data that length is 4 always;

    //approch 2:
        if(s1.size() != s2.size()){
            return false;
        }
        else{
            for(int i = 0;i<s1.size();i++){
                if(s1[i] == s2[i]){
                    continue;
                }
                else if(s1[i+2] == s2[i]){
                    swap(s1[i],s1[i+2]);
                }
            }
            return s1==s2;
        }


    }
};