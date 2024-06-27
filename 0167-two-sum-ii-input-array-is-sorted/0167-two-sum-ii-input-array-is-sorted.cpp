class Solution {
public:
//appraoch 1: TLE --> O(nlogn)
    // int bs(vector<int>numbers,int target,int a){
    //     int i = a + 1;
    //     int j = numbers.size()-1;
    //     while(i<=j){
    //         int mid = (i+j)/2;
    //         if(numbers[mid] == target){
    //             return mid;
    //         }
    //         else if (numbers[mid] > target){
    //             j = mid - 1;
    //         }
    //         else{
    //             i = mid + 1;
    //         }
    //     }

    //     return -1;
    // }

    // vector<int> twoSum(vector<int>& numbers, int target) {
    //     int a;
    //     int b;
    //     for(int i = 0;i<numbers.size()-1;i++){
    //         int num = target - numbers[i];
    //         a = i;
    //         b = bs(numbers,num,a);
    //         if(b != -1 && a != b){
    //             return {a+1,b+1};
    //         }
    //     }
    //     return {0,0};
    // }

//approach 2: 
    vector<int> twoSum(vector<int>& numbers, int target) {
        int i = 0;
        int j = numbers.size()-1;
        
        while(i<j){
            int sum = numbers[i] + numbers[j];

            if(sum == target){
                return {i+1,j+1};
            }
            else if (sum > target){
                j--;
            }
            else{
                i++;
            }
        }

        return {0,0};
    }
};