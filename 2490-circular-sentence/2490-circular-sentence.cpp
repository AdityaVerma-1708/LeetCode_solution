class Solution {
public:
    bool isCircularSentence(string sentence) {
        if(sentence[0] != sentence[sentence.size()-1]){
            return false;
        }
        else{
            int j = 0;
            while(j < sentence.size()){
                int i = j;
                while(i < sentence.size() && sentence[i] != ' '){
                    i++;
                }
                if(i == sentence.size()){ //means the word is the last word 
                    return true;
                }
                else{
                    if(sentence[i-1] != sentence[i+1]){
                        return false;
                    }
                }

                j = i+1;
            }
            return true;
            
        }
    }
};