class Solution {
public:
    bool isValid(int i, int j, int n, int m, vector<vector<int>>& grid) {
        if(i < 0 || j < 0 || i >= n || j >= m || grid[i][j] == 0) return false;
        return true;
    }
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int, int>>q;
        int n = grid.size(), m = grid[0].size();
        
        for(int i = 0;i<n;i++) { 
            for(int j = 0;j<m;j++) {
                if(grid[i][j] == 2) {
                    q.push({i, j});
                    grid[i][j] = 0;
                }
            }
        }
        
        int ans = 0;
        
        vector<int>dx = {-1, 0, 1, 0};
        vector<int>dy = {0, 1, 0, -1};
        while(!q.empty()) {
            int size = q.size();
            ans++;
            
            for(int i = 0;i<size;i++) {
                auto [x, y] = q.front();
                q.pop();
                for(int j = 0;j<4;j++) {
                    if(isValid(x + dx[j], y + dy[j], n, m, grid)) {
                        q.push({x + dx[j], y + dy[j]});
                        grid[x + dx[j]][y + dy[j]] = 0;
                    }
                }
            }
        }
        
        for(int i = 0;i<n;i++) {
            for(int j = 0;j<m;j++) {
                if(grid[i][j] == 1) return -1;
            }
        }
        
        if(ans == 0) return 0;
        return ans - 1;
    }
};