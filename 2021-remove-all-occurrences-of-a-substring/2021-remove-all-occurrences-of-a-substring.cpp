class Solution {
public:
    string removeOccurrences(string s, string part) {

        while(s.length() != 0 && s.find(part) < s.length()){
            s.erase(s.find(part),part.length());
        }
        return s;
        //we will traverse the array, till length of the array gets reduced to zero 
        //or if find function finds the part and return the iterator to the first 
        //element of the part, and if it does not find the part it will return the 
        //end iterator which we smaller than the s.length

        //inside we are erasing the part from the string
    }
};