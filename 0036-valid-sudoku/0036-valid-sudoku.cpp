class Solution
{
public:
    bool isValidSudoku(vector<vector<char> > &board)
    {
        int m1[9][9] = {0}, m2[9][9] = {0}, m3[9][9] = {0};
        
        for(int i = 0; i < board.size(); ++ i)
            for(int j = 0; j < board[i].size(); ++ j)
                if(board[i][j] != '.')
                {
                    int num = board[i][j] - '0' - 1, k = i / 3 * 3 + j / 3;
                    if(m1[i][num] || m2[j][num] || m3[k][num])
                        return false;
                    m1[i][num] = m2[j][num] = m3[k][num] = 1;
                }
        
        return true;
    }
};