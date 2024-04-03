// class Solution {
// public:
//     bool solve(int i, int j, vector<vector<char>>& board, string word, int k,
//                vector<vector<bool>>& visited) {

//         if(i < 0 || i >= board.size() || j < 0 || j >= board[0].size()){
//             return false;
//         } 

//         // if (k >= word.size()) {
//         //     return true;
//         // }

//         if (toupper(board[i][j]) == toupper(word[k]) && visited[i][j] == false && k == word.size()-1) {
//             return true;
//         }

//         else if (toupper(board[i][j]) == toupper(word[k]) && visited[i][j] == false && k < word.size()-1) {
            
//             visited[i][j] = true;
//             bool check = true;
//             // go up
//             check = solve(i-1, j, board, word,k+1,visited);

//             // go down
//             if(check == false){
//                 check = solve(i+1, j, board, word, k+1,visited);
//             }
            
//             // go left
//             if(check == false){
//                 check = solve(i, j-1, board, word, k+1,visited);
//             }
            
//             // go right
//             if(check == false){
//                 check = solve(i, j+1, board, word, k+1,visited);
//             }
            
//             if(check == true){
//                 return true;
//             }

//             visited[i][j] = false;
//         }
//         return false;
//     }

//     bool exist(vector<vector<char>>& board, string word) {
//         // brute force

//         if(board.empty() || word.empty()) {
//             return false;
//         }

//         int k = 0;
//         vector<vector<bool>> visited(board.size(), vector<bool>(board[0].size(), false));

//         for (int i = 0; i < board.size(); i++) {
//             for (int j = 0; j < board[i].size(); j++) {
//                 if (toupper(board[i][j]) == toupper(word[0])) {
//                     if (solve(i, j, board, word,k,visited) == true) {
//                         return true;
//                     }
//                 }
//             }
//         }
//         return false;
//     }
// };

class Solution {
public:
    bool solve(int i, int j, vector<vector<char>>& board, string word, int k,
               vector<vector<bool>>& visited) {

        if(i < 0 || i >= board.size() || j < 0 || j >= board[0].size()){
            return false;
        } 

        // if (k >= word.size()) {
        //     return true;
        // }

        if (board[i][j] == word[k] && visited[i][j] == false && k == word.size()-1) {
            return true;
        }

        else if (board[i][j] == word[k] && visited[i][j] == false && k < word.size()-1) {
            
            visited[i][j] = true;
            bool check = true;
            // go up
            check = solve(i-1, j, board, word,k+1,visited);

            // go down
            if(check == false){
                check = solve(i+1, j, board, word, k+1,visited);
            }
            
            // go left
            if(check == false){
                check = solve(i, j-1, board, word, k+1,visited);
            }
            
            // go right
            if(check == false){
                check = solve(i, j+1, board, word, k+1,visited);
            }
            
            if(check == true){
                return true;
            }

            visited[i][j] = false;
        }
        return false;
    }

    bool exist(vector<vector<char>>& board, string word) {
        // brute force

        if(board.empty() || word.empty()) {
            return false;
        }

        int k = 0;
        vector<vector<bool>> visited(board.size(), vector<bool>(board[0].size(), false));

        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[i].size(); j++) {
                if (board[i][j] == word[0]) {
                    if (solve(i, j, board, word,k,visited) == true) {
                        return true;
                    }
                }
            }
        }
        return false;
    }
};