class Solution {
public:
    int maxi(vector<int> piles){
        int ans = INT_MIN;
        for(int i = 0;i<piles.size();i++){
            ans = max(ans,piles[i]);
        }
        return ans;
    }

    int total(vector<int> piles,int n){
        int ans = 0;
        for(int i = 0;i<piles.size();i++){
            if(piles[i] <= n){
                ans = ans + 1;
            }
            else{
                if(piles[i]%n == 0){
                    ans = ans + (piles[i]/n);
                }
                else{
                    ans = ans + (piles[i]/n) + 1;
                }
            }
        }
        return ans;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
    //approach 1:
        //bs on answers
        int i = 1;
        int j = maxi(piles);
        int ans = j+1;
        while(i <= j){
            int mid = (i+j)/2;

            if(total(piles,mid) <= h){
                ans = min(ans,mid);
                j = mid - 1;
            }
            else{
                i = mid + 1;
            }
        }
        return ans;
    }
};