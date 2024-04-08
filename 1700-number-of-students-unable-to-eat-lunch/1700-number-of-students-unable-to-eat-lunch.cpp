class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
    //brute force
        // int sand1 = 0;
        // int sand0 = 0;

        int stu1 = 0;
        int stu0 = 0;

        for(int num : students){
            if(num == 1){
                stu1++;
            }
            else{
                stu0++;
            }
        }

        // for(int num : sandwiches){
        //     if(num == 1){
        //         sand1++;
        //     }
        //     else{
        //         sand0++;
        //     }
        // }

        int ans  = 0;
        for(int num : sandwiches){
            if(num == 0){
                if(stu0 == 0){
                    ans = stu0 + stu1;
                    break;
                }
                else{
                    stu0--;
                }
            }
            else{
                if(stu1 == 0){
                    ans = stu1 + stu0;
                    break; 
                }
                else{
                    stu1--;
                }
            }
        }
        return ans;
        
    }
};