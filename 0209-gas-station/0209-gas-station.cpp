class Solution {
public:
    
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
        int i, j, k=1, s=0, N=gas.size();
        
        vector<int> res, cums;
        
        
        for(i=0; i<N; i++) {
            res.push_back( gas.at(i) - cost.at(i));
        }
        
        j = 0;
        for(i=0; i<N; i++) {
            s = s + res[i];
            cums.push_back(s);
            if(cums[i] <0) j++;
        }
        if(j==0) return 0;
        else if(N==1) return -1;
        else 
        do {
                
                   
                for(i=k; i<N+k; i++) {
                    if(cums[k-1] >=0) break; 
                    else if(i<N &&cums[i]- cums[k-1] < 0) break;
					else if(i>=N &&cums[i%N] -cums[k-1] +  cums[N-1] <0) break;
                }
                
                if(i==N+k) return k;
                else k++;
        }while(k<N);
        
        if(k==N) return -1;
        
        
    }
};