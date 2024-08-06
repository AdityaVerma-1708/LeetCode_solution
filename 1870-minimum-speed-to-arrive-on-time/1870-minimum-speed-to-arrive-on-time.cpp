class Solution {
public:

    double count(vector<int>& dist,int speed){
        double totaltime = 0.0;
        for(int i = 0;i<dist.size();i++){
            if(i == dist.size()-1){
                totaltime = totaltime + (double)dist[i]/speed;
            }
            else{
                if(dist[i]%speed == 0){
                    totaltime = totaltime + (dist[i]/speed);
                }
                else{
                    totaltime = totaltime + (dist[i]/speed) + 1;
                }
            } 
        }

        return totaltime;
    }

    int minSpeedOnTime(vector<int>& dist, double hour) {
    //approach 1:   
        int mini = 0;
        int maxi = 0;
        int totaldistance = 0;
        for(int i = 0;i<dist.size();i++){
            totaldistance = totaldistance + dist[i];
        }

        mini = 1;
        maxi = 1e7;

        for(int i = mini;i<=maxi;i++){
            if(count(dist,i) <= hour){
                return i;
            }
        }

        return -1;
    }
};