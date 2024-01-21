class Solution {
public:
    int divisorSubstrings(int num, int k) {
    //appraoch 1:
        string s = to_string(num);
        int i = 0;
        int j = k-1;
        int ans = 0;
        while(j < s.size()){
            string ss = s.substr(i,k);
            int n = stoi(ss);
            
            if(n != 0 && num%n == 0){
                ans++;
            }
            j++;
            i++;
        }
        return ans;
    }
};