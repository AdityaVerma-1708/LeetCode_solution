class Solution {
public:
    int lengthOfLastWord(string s) {
        // int count=0;

        // if(s.back() == ' '){
        //     while(s.back() == ' '){
        //         s.pop_back();
        //     }
        // }

        // while(s.back() != ' ' && s.length() != 0){
        //     s.pop_back(); //here we have added length command since sor some cases if size become 0 than 
        //     count++;    //loops shows error
        // }
        
        // return count;

    //appraoch 2:
        int ans = 0;
        while(s.back() == ' '){
            s.pop_back();
        }

        while(s.length() != 0 && s.back() != ' '){
            s.pop_back();
            ans++;
        }
        return ans;
    }
};