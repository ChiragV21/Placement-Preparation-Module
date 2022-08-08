class Solution {
public:
    vector<vector<string>> ans;
    
    bool isSafe(vector<vector<int>>& board, int i, int j, int n) {
        int x = 0;
        int y = j;
        while(x < i)
            if(board[x++][y])
                return false;
        x = i;
        y = j;
        while(x >= 0 and y >= 0) 
            if(board[x--][y--])
                return false;
        x = i;
        y = j;
        while( x>=0 and y < n)
            if(board[x--][y++])
                return false;
        return true;
    }
    
    bool solve(vector<vector<int>>& board, int i, int n) {
        if(i == n) {
            vector<string> fin;
            
            for(int i = 0; i < n; i++) {
                string str;
                
                for(int j = 0; j < n; j++) 
                    if(board[i][j] == 1)
                        str += 'Q';
                    else
                        str += '.';
                
                fin.push_back(str);
            }
            
            ans.push_back(fin);
            return false;
        }
        for(int j = 0; j < n; j++) {
            if(isSafe(board, i, j, n)) {
                board[i][j] = 1;
                
                bool kyaQueenRakhPaaRaheHai = solve(board, i+1, n);
                
                if(kyaQueenRakhPaaRaheHai)
                    return true;
                
                board[i][j] = 0;
            }
        }
        
        return false;
    }
    
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<int>> board(n, vector<int> (n, 0));
        solve(board, 0, n);
        return ans;
    }
};