class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        std::unordered_map<int,std::vector<char>> row;
        std::unordered_map<int,std::vector<char>> col;
        std::unordered_map<int,std::vector<char>> box;
        for(int i=0; i<9; i++){
            row[i].reserve(9);
            col[i].reserve(9);
            box[i].reserve(9);
        }
        for(int r=0; r<9; r++){
            for(int c=0; c<9; c++){
                char val = board[r][c];
                int boxIndex = (r/3)*3 + (c/3); //converting 2D indexed location to 1D
                if(board[r][c] == '.')
                    continue;
                else if(std::find(row[r].begin(), row[r].end(), val) != row[r].end() ||
                        std::find(col[c].begin(), col[c].end(), val) != col[c].end() ||
                        std::find(box[boxIndex].begin(),box[boxIndex].end(), val) != box[boxIndex].end()){
                    return false;
                }
                else{
                    row[r].emplace_back(val);
                    col[c].emplace_back(val);
                    box[boxIndex].emplace_back(val);
                }
            }
        }
        return true;
    }
};
