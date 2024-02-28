class Solution {
public:
    int lengthOfLongestSubstring(string s) {
    //apprcoh 1: using extra space  

        // set<int> sett;
        // int count=1;
        // int i=0;
        // int j=1;
        // int flag = 0; 

        // if(s.size() <= 1){
        //     return s.size();
        // }
        // else if(s.size()==2){     
        //     if(s[0] == s[1]){
        //         return 1;
        //     }
        //     else{
        //         return 2;
        //     }
        // }
        // else{                   
        //     while(j < s.size()){
        //         if(s[i] == s[j]){
        //             sett.insert(count);
        //             count = 1;
        //             i++;
        //             j = i+1;
        //         }
        //         else{
        //             for(int k=i;k<j;k++){
        //                 if(s[k] == s[j]){
        //                     flag = 1;
        //                 }
        //             }
        //             if(flag == 0){
        //                 j++;
        //                 count++;
        //                 sett.insert(count);
        //             }
        //             else{
        //                 sett.insert(count);
        //                 count = 1;
        //                 i++;
        //                 j = i+1; 
        //             }
        //             flag = 0;
        //         }
        //     }
        // }
        // int max = *(sett.rbegin());
        // return max;

    //approch 2:
        int ans = 0;
        int count = 1;
        int i = 0;
        int j = 1;
        int flag = 0;
        if(s.size() <= 1){
            return s.size();
        }
        else if(s.size()==2){     
            if(s[0] == s[1]){
                return 1;
            }
            else{
                return 2;
            }
        }  
        else{
            while(j<s.size()){
                if(s[i] == s[j]){
                    ans = max(count,ans);
                    count = 1;
                    i++;
                    j = i+1;
                }
                else{
                    for(int k = i;k<j;k++){
                        if(s[k] == s[j]){
                            flag = 1;
                            break;
                        }
                    }
                    if(flag == 0){
                        count++;
                        j++;
                        ans = max(ans,count);
                    }
                    else{
                        ans = max(ans,count);
                        count = 1;
                        i++;
                        j = i + 1;
                    }
                }
                flag = 0; 
            }
        } 
        return ans;
    }
};