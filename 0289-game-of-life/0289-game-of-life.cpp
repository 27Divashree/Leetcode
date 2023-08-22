class Solution {
public:
    void gameOfLife(vector<vector<int>>& Oboard) {
        int n = Oboard.size();
        int m = Oboard[0].size();
        vector<vector<int>> board = Oboard;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                int live = 0;
                if(i>0)
                {
                    if(board[i-1][j]==1)    //up
                        live++;
                    
                    if(j>0)
                    {
                        if(board[i-1][j-1]==1) //left up
                            live++;
                    }

                    if(j<m-1)
                    {
                        if(board[i-1][j+1]==1) //right up
                            live++;
                    }
                }
                if(i<n-1)
                {
                    if(board[i+1][j]==1)    //down
                        live++;
                    
                    if(j>0)
                    {
                        if(board[i+1][j-1]==1)  //down left
                            live++;
                    }

                    if(j<m-1)
                    {
                        if(board[i+1][j+1]==1)  //down right
                            live++;
                    }   
                }
                if(j>0){
                    if(board[i][j-1]==1) //left
                        live++;
                }
                if(j<m-1)  //right
                {
                    if(board[i][j+1]==1)
                        live++;
                }

                if(board[i][j]==1 && live<2)
                    Oboard[i][j]=0;

                else if(board[i][j]==1 && (live==2 || live==3))
                    Oboard[i][j]=1;

                else if(board[i][j]==1 && live>3)
                    Oboard[i][j]=0;
                    
                else if(board[i][j]==0 && live==3)
                    Oboard[i][j]=1;
            }
        }
    }
};