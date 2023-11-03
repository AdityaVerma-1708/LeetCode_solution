class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
    //apprcoh 1:    
        vector<string> ans;
        string s1 = "Push";
        string s2 = "Pop";
        int i = 1;
        int j = 0;
        while(i<=n && j<target.size()){
            if(ans.empty() && target[j] == i){
                ans.push_back(s1); //push
                i++;
                j++;
            }
            else if(ans.empty() && target[j] != i){
                ans.push_back(s1); //push;
                ans.push_back(s2);
                i++;
            }
            else if(!ans.empty() && target[j] == i){
                ans.push_back(s1);
                i++;
                j++;
            }
            else if(!ans.empty() && target[j] != i){
                ans.push_back(s1); //push
                ans.push_back(s2);
                i++;
            }
        }
        return ans;

     
    }
};