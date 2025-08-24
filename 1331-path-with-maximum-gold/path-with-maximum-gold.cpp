class Solution {
private:
    int m, n;
    int ans = -1;
    int dx[4] = {-1, 0, 1, 0};
    int dy[4] = {0, 1, 0, -1};

    bool isValid(int r, int c, int m, int n) {
        return r >= 0 && r < m && c >= 0 && c < n;
    }

    void dfs(int r,int c, vector<vector<int>> &vis, vector<vector<int>>&grid, int &cnt){
        vis[r][c] = 1;
        cnt += grid[r][c];
        ans = max(ans, cnt);

        for(int i=0;i<4;i++){
            int nr = r + dx[i];
            int nc = c + dy[i];
            if(isValid(nr,nc,m,n) && grid[nr][nc] > 0 && !vis[nr][nc]){
                dfs(nr,nc,vis,grid,cnt);
            }
        }

        vis[r][c] = 0;      
        cnt -= grid[r][c];   
    }

public:
    int getMaximumGold(vector<vector<int>>& grid) {
        m = grid.size();       
        n = grid[0].size();    
        vector<vector<int>> vis(m, vector<int>(n, 0));

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                int cnt = 0;
                if(grid[i][j] > 0){
                    dfs(i,j,vis,grid,cnt);
                }
                  ans = max(ans, cnt);
            }
        }
        return ans;
    }
};
