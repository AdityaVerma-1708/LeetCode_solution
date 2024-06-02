class Solution {
public:
    void reverseString(vector<char>& s) {
    //approch 1:
        // if(s.size()>1){
        //     for(int i=0;i<s.size()/2;i++){
        //         char temp = s[i];
        //         s[i] = s[s.size()-1-i];
        //         s[s.size()-1-i] = temp;
        //     }
        // }
    //approch 2:
        int i=0;
        int j=s.size()-1;
        while(i<j){
            swap(s[i],s[j]);
            i++;
            j--;
        }
    }
};