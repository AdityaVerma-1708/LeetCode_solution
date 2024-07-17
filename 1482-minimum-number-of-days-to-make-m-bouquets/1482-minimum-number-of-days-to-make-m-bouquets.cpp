class Solution {
public:
    int maxi(vector<int> arr){
        int ans = INT_MIN;
        for(int i = 0;i<arr.size();i++){
            ans = max(ans,arr[i]);
        }
        return ans;
    }

    int conseflower(vector<int> arr,int day,int k){
        if(k == 1){
            int ans = 0;
            for(int i = 0;i<arr.size();i++){
                if(arr[i] <= day){
                ans++;
                }
            }
            return ans;
        }
        else{
            int i = 0;
            int j = 0;
            int ans = 0;

            int temp = 0;
            while(j < arr.size()){
                if(j-i + 1 != k){
                    if(arr[j] <= day){
                        temp++;
                    }
                    j++;
                }
                else{
                    if(arr[j] <= day){
                        temp++; 
                    }
                    if(temp == k){
                        ans++;
                        j++;
                        i = j;
                        temp = 0;
                    }
                    else{
                        if(arr[i] <= day){
                            temp--;
                        }
                        i++;
                        j++;
                    }
                }
            }
            cout<<ans<<endl;
            return ans;
        }
    }

    int minDays(vector<int>& bloomDay, int m, int k) {
    //appraoch 1L:
        long long total = (long long)m * k; 
        if(bloomDay.size() < total){
            return -1;
        }
        else{
            int i = 1; //minium wait
            int j = maxi(bloomDay);
            int ans = INT_MAX;

            while(i<=j){
                int mid = (i+j)/2;

                if(conseflower(bloomDay,mid,k) >= m){
                    ans = min(ans,mid);
                    j = mid - 1;
                }
                else{
                    i = mid + 1;
                }
            }
            return ans;
        }
    }
};