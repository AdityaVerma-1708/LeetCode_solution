class Solution {
public:
    int strStr(string haystack, string needle) {
    //approch 1: wrong ans for test case 59
        // if(haystack.length() < needle.length()){
        //     return -1;
        // }
        // if(haystack.length() == needle.length()){
        //     return 0;
        // }
        // else{
        //     int i=0,j,n,flag=0;
        //     const int m = 0;
        //     while(i<haystack.length()){
        //         if(haystack[i] == needle[m]){  //59th test case try to solve
        //             n=m;
        //             j=i;
        //             while(n<needle.length()){
        //                 if(haystack[j] != needle[n]){
        //                     flag=1;
        //                     break;
        //                 }
        //                 n++;
        //                 j++;
        //             }
        //             if(flag==0){
        //                 return i;
        //             }
        //         }
        //         i++;    
        //     } 
        // }
        // return -1;

    //approch 2: by using the find function ()
        // int temp = haystack.find(needle);
        // if(temp > haystack.size()){
        //     return -1;
        // }
        // return temp;

    //approch 3:
        if(haystack.size() < needle.size()){
            return -1;
        }
        else if(haystack.size() == needle.size()){
            if(needle == haystack){
                return 0;
            }
            else{
                return -1;
            }
        }
        else{
            int i=0;
            while(i<haystack.size()){
                if(haystack[i] == needle[0]){
                    string str = haystack.substr(i,needle.size());
                    if(str == needle){
                        return i;
                    }
                }
                i++;
            }
        }
        return -1;

    }
};