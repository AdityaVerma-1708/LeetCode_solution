class Solution {
public:

    int count(vector<int>& time,long long timee){
        int trips = 0;
        for(int i = 0;i<time.size();i++){
            trips = trips + (timee/time[i]);
        }

        return trips;
    }

    long long min(long long a,long long b){
        if(a > b){
            return b;
        }
        else{
            return a;
        }
    }

    long long minimumTime(vector<int>& time, int totalTrips) {
    //brute force: TLE

        // long long mini = INT_MAX;
        // long long maxi = 0;
        // for(int i = 0;i<time.size();i++){
        //     mini = min(time[i],mini);
        // } 
        // maxi = mini*totalTrips;

        // for(long long i = mini;i<=maxi;i++){
        //     if(count(time,i) >= totalTrips){
        //         return i;
        //     }
        // }  

        // return -1;

    //binary search 
        long long mini = INT_MAX;
        long long maxi = 0;
        for(int i = 0;i<time.size();i++){
            mini = min(time[i],mini);
        } 
        maxi = mini*totalTrips;

        long long ans = 0;
        while(mini <= maxi){
            long long mid = (mini + maxi)/2;
            if(count(time,mid) >= totalTrips){
                ans = mid;
                maxi = mid - 1;
            }
            else{
                mini = mid + 1;
            }
        }
        return ans;

    }
};