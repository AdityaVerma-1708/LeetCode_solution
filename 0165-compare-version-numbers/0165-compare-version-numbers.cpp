class Solution {
public:
    int solve(string version1,string version2,int i,int j){
        string s1 = "0";
        string s2 = "0";

        while(i < version1.size() && version1[i] != '.'){
            s1 = s1 + version1[i];
            i++;
        }

        while(j < version2.size() && version2[j] != '.'){
            s2 = s2 + version2[j];
            j++;
        }
        
        //convert both into numbers;

        int n1 = stoi(s1);
        int n2 = stoi(s2);

        if(n1 > n2){
            return 1;
        }
        else if(n1 < n2){
            return -1;
        }
        else{
            if(i >= version1.size() && j >= version2.size()){
                return 0;
            }

            return solve(version1,version2,i+1,j+1);
        }
    }

    int compareVersion(string version1, string version2) {
    //brute force:
        return solve(version1,version2,0,0);
    }
};