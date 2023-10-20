class Solution {
public:
    string removeDuplicates(string s) {

//*******VERY GOOD QUESTION**********
    //approch 1: memory limit exceed (used recursion)    
        // int i=0;
        // int a=-1,b=-1;
        // string ans;
        // for(int j=1;j<s.size();j++){
        //     int i = j - 1;
        //     if(s[i] == s[j]){
        //         a = i,b = j;
        //         break;
        //     }
        // }

        // for(int i = 0;i<s.size();i++){
        //     if(i != a && i != b){
        //         ans.push_back(s[i]);
        //     }
        // }

        // //if no equal adjacent is there
        // if(a ==-1 && b == -1){
        //     return ans;
        // }

        // //else use recursion
        // return removeDuplicates(ans);

    //approch 2: TLE recursion with not using another string 
        // // we can use the erase function
        // int a=-1,b=-1;
        // for(int j=1;j<s.size();j++){
        //     int i = j - 1;
        //     if(s[i] == s[j]){
        //         a = i,b = j;
        //         break;
        //     }
        // }

        // //if no equal adjacent is there
        // if(a ==-1 && b == -1){
        //     return s;
        // }

        // s.erase(a,2);

        // //else use recursion
        // return removeDuplicates(s);

     //we have to skip the recurrsion and do something else

    //approch 3: using while loop(all test case passed but TLE)
        // int i=1;
        // while(i < s.size() ){
        //     if(s[i] == s[i-1]){
        //         s.erase(i-1,2);
        //         i = 1;
        //     }
        //     else{
        //         i++;
        //     }
        // }
        // return s;

    //approch 4: beasically we have to skip using erase function
        string ans;
        int i=0;
        while(i < s.size()){
            if(ans.empty() || ans.back() != s[i]){
                ans.push_back(s[i]);
            }
            else{
                ans.pop_back();
            }
            i++;
        }
        return ans;  
    }
};