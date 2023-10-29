class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
    //approch 1: wrong ans for some test cases
        // vector<vector<int>> ans;
        // for(int i=0;i<intervals.size();i++){
        //     int s1 = intervals[i][0];
        //     int e1 = intervals[i][1];

        //     for(int j=i+1;j<intervals.size();j++){
        //         int s2 = intervals[j][0];
        //         int e2 = intervals[j][1];

        //         if(s2>e1){
        //             //no overlapping... push both to ans
        //             vector<int> temp1{s1,e1};
        //             ans.push_back(temp1);
        //             vector<int> temp2{s2,e2};
        //             ans.push_back(temp2);
        //         }
        //         else{   //overlapping
        //             if(s1>=s2){   //second starting is dominant
        //                 if(e2>e1){
        //                     vector<int> temp{s2,e2};
        //                     ans.push_back(temp);  
        //                 }
        //                 else{
        //                     vector<int> temp{s2,e1};
        //                     ans.push_back(temp);
        //                 }
        //                 break;

        //             }
        //             else{  //first starting is dominant
        //                 if(e2>e1){
        //                     vector<int> temp{s1,e2};
        //                     ans.push_back(temp);  
        //                 }
        //                 else{
        //                     vector<int> temp{s1,e1};
        //                     ans.push_back(temp);
        //                 }
        //                 break;
        //             }
        //         }
        //     }
            
        // }
        // return ans;

    //approch 3: 
        if(intervals.size()<=1){
            return intervals;
        }
        sort(intervals.begin(),intervals.end());
        vector<vector<int>> ans;

        for(int i=0;i<intervals.size();i++){
            int s = intervals[i][0];
            int e = intervals[i][1];

            if(!ans.empty() && ans.back()[1] >= e){
                continue; //overlapping
            }
            else{
                for(int j=i+1;j<intervals.size();j++){
                    if(intervals[j][0] <= e){ //overlapping
                        e = max(intervals[j][1],e);
                        s = min(intervals[j][0],s);
                    }
                    else{
                        break;
                    }
                }
                ans.push_back({s,e});
            }
            
            
        }
        return ans;


    //approch 3: stack in single loop
        // sort(intervals.begin(),intervals.end());
        // if(intervals.size()<=1){
        //     return intervals;
        // }

        // vector<vector<int>> ans;
        // ans.push_back(intervals[0]);
        // int j=0;
        // for(int i=1;i<intervals.size();i++){
        //     if(ans[j][1]>=intervals[i][0]){   //overlapping is there
        //         int s = min(ans[j][0],intervals[i][0]);   //new starting
        //         int e = max(intervals[i][1],ans[j][1]);  //new ending
        //         ans.pop_back();
        //         ans.push_back({s,e});
        //     }
        //     else{
        //         ans.push_back(intervals[i]);
        //         j++;
        //     }
        // }
        // return ans;
    }


};