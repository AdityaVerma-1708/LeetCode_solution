class Solution {
public:
    int minimumRecolors(string blocks, int k) {
    //appraoch 1:  
        int i = 0;
        int j = k-1;
        int to = 0;

        for(int a = 0; a < k; a++){
            if(blocks[a] == 'W'){
                to++;
            }
        }
        int ans = to;

        while(j < blocks.size()){
            if(j == blocks.size()-1){
                break;
            }
            
            if(blocks[i] == 'W'){
                to--;
            }
            i++;

            if(blocks[j+1] == 'W'){
                to++;
            }
            j++;

            ans = min(ans,to);
        }

        return ans;
    }
};