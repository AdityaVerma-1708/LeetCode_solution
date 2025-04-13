class Solution {
public:

    long long find(vector<vector<int>>& q, long long maxpoints,int k, int i){
        if(i >= q.size()){
            return maxpoints;
        }

        if(k > 0){
            return find(q,maxpoints,k-1,i+1);
        }
        else{
            //if k == 0         take                            skip
            return max(find(q,maxpoints + q[i][0],q[i][1],i+1),find(q,maxpoints,k,i+1));
        }
    }

    long long mostPoints(vector<vector<int>>& questions) {
        return find(questions,0,0,0);
    }
};