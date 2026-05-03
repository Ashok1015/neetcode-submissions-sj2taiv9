class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        //sudoku contains value 1-9 and no 0 so the 0th entry in every second index would be false.
        //The 10 indices constitute boolean values for numbers 0-9

        bool row[9][10] = {false};
        bool col[9][10] = {false};
        bool box[9][10] = {false};
        for(int r=0; r<9; r++){
            for(int c=0; c<9; c++){
                int val= board[r][c] - '0';
                int boxIndex = (r/3)*3 + (c/3);
                if(board[r][c]=='.')
                    continue;
                else if(row[r][val] || col[c][val] || box[boxIndex][val]){
                    return false;
                }
                else{
                    row[r][val] = true;
                    col[c][val] = true;
                    box[boxIndex][val] = true;
                }
            }
        }
        return true;
    }
};
