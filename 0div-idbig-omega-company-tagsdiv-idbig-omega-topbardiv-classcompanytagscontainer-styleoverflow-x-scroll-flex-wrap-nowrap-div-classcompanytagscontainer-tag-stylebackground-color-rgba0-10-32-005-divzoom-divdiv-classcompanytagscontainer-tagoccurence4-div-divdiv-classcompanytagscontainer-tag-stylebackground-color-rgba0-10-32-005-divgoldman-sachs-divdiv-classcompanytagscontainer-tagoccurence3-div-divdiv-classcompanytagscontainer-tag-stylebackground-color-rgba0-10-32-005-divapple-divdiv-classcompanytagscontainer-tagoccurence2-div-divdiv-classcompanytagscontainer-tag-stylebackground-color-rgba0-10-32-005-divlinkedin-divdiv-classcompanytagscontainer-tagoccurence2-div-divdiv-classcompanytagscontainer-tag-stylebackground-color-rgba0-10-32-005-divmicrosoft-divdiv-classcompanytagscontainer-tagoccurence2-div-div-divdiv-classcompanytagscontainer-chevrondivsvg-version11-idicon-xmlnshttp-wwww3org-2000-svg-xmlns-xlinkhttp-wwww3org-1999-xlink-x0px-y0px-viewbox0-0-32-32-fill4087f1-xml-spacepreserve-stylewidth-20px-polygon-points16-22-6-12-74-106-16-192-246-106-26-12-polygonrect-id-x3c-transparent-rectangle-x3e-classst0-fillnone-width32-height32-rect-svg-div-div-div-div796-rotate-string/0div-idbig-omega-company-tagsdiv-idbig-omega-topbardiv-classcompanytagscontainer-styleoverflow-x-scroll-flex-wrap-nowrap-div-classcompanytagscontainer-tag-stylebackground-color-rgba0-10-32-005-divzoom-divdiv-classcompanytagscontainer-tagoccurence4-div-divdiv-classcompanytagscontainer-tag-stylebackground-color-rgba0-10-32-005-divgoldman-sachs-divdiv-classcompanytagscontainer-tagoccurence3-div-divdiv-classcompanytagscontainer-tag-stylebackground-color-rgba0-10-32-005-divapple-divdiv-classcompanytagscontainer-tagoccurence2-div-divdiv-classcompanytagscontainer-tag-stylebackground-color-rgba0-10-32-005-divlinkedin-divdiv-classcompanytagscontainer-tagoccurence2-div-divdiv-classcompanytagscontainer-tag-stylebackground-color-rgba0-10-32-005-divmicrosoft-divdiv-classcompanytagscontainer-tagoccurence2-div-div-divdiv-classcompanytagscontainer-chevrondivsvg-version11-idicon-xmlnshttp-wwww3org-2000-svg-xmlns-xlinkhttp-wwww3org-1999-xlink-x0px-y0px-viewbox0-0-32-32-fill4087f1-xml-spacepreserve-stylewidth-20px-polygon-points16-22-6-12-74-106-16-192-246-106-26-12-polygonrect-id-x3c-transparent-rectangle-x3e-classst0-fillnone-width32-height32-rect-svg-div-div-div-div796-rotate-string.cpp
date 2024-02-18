class Solution {
public:
    bool rotateString(string s, string goal) {
    //brute force:
        // if(s.size() != goal.size()){
        //     return false;
        // }    
        // else{
        //     int i = 0;
        //     while(i<s.size()){
        //         char temp = s[0];
        //         for(int j = 1;j<s.size();j++){
        //             s[j-1] = s[j];
        //         }
        //         s[s.size()-1] = temp;

        //         if(s == goal){
        //             return true;
        //         }
        //         i++;
        //     }
        //     return false;
        // }
        
    //appraoch 2:  O(n)

        // if(s.size() != goal.size()){
        //     return false;
        // }
        // else{
        //     int i = 0;
        //     int j = 1;
        //     while(j != s.size()){
        //         char ch = s[i];
        //         size_t findd = goal.find(ch);
        //         if(findd == string::npos){
        //             return false;
        //         }
        //         else{
        //             if(goal[(findd+1)%goal.size()] != s[i+1]){
        //                 return false;
        //             }
        //         }
        //         i++;
        //         j++;
        //     }
        //     return true;
        // }

    //appraoch 3: most optimised 
        if(s.size() != goal.size()){
            return false;
        }
        s = s + s;
        if(s.find(goal) == string::npos){
            return false;
        }
        return true;
    }
};