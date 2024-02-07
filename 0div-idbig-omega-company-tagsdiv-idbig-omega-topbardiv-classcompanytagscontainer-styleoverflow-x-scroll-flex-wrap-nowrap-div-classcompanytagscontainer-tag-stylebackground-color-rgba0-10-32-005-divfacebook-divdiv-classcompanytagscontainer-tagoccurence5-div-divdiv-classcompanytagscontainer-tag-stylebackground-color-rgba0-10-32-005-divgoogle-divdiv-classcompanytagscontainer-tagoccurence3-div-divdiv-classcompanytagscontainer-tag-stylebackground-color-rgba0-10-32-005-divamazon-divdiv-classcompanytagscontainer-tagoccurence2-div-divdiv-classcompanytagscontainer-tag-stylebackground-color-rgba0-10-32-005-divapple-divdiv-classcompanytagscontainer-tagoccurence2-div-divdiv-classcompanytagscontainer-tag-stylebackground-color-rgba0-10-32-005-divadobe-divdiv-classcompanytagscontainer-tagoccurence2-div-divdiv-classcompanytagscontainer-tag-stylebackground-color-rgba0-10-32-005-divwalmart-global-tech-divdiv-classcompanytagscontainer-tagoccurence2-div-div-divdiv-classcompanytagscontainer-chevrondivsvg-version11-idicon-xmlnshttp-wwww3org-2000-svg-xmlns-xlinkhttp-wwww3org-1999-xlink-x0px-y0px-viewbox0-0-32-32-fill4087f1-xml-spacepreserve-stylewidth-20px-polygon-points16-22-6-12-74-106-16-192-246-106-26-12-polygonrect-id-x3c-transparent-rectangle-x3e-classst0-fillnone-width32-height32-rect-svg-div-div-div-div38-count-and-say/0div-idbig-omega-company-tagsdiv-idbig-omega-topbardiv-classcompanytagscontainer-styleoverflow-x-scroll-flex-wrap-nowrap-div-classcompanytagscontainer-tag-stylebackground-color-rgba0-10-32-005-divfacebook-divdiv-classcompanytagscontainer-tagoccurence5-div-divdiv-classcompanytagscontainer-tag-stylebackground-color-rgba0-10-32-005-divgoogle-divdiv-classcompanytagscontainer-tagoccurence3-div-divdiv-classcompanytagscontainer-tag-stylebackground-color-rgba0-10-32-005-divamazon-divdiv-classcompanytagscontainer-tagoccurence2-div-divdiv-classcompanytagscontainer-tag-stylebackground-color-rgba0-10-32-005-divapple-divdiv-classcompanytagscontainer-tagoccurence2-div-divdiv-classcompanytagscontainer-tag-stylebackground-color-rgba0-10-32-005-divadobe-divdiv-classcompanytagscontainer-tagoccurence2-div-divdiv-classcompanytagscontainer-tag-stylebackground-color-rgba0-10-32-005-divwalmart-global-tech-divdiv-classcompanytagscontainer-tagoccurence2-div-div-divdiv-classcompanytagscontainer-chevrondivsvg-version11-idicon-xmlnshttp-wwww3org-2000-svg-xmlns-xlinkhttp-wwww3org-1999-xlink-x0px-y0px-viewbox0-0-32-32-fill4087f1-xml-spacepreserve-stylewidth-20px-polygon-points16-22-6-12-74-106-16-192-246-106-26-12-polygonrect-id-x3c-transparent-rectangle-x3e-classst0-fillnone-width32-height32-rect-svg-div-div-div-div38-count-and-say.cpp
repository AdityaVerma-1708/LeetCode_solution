class Solution {
public:

    string say(string temp){
        string ans = "";
        int count = 1;
        int i = 1;
        while(i < temp.size()){
            if(temp[i] == temp[i-1]){
                count++;
                i++;
            }
            else if(temp[i] != temp[i-1]){
                ans = ans + to_string(count) + temp[i-1];
                count = 1;
                i++;
            }
        }

        ans = ans + to_string(count) + temp[i-1];

        return ans;
    }

    string countAndSay(int n) {
    //appraoch 1:
        if(n == 1){
            return "1";
        }

        string prev = countAndSay(n-1);
        return say(prev);
    }
};