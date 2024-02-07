class Solution {
public:
//appraoch 1: using recurrsion
    // string say(string temp){
    //     string ans = "";
    //     int count = 1;
    //     int i = 1;
    //     while(i < temp.size()){
    //         if(temp[i] == temp[i-1]){
    //             count++;
    //             i++;
    //         }
    //         else if(temp[i] != temp[i-1]){
    //             ans = ans + to_string(count) + temp[i-1];
    //             count = 1;
    //             i++;
    //         }
    //     }

    //     ans = ans + to_string(count) + temp[i-1];

    //     return ans;
    // }

    // string countAndSay(int n) {
    // //appraoch 1:
    //     if(n == 1){
    //         return "1";
    //     }

    //     string prev = countAndSay(n-1);
    //     return say(prev);
    // }

//approach 2: using loops
    string countAndSay(int n){
        if(n == 1){
            return "1";
        }

        int i = 2;
        string ans = "1";
        while(i<=n){
            string temp = "";
            int j = 1;
            int count = 1;
            while(j<ans.size()){
                if(ans[j] ==  ans[j-1]){
                    count++;
                    j++;
                }
                else if(ans[j] != ans[j-1]){
                    temp = temp + to_string(count) + ans[j-1];
                    count = 1;
                    j++;
                }
            }

            temp = temp + to_string(count) + ans[j-1];
            ans = temp;
            temp = "";

            i++;
        }

        return ans;
    }
};