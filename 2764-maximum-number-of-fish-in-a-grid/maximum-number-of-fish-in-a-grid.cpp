class Solution {
public:
   bool isValid(int nr,int nc,int m, int n){
        return nr>=0 && nc>=0 && nr<m && nc<n;
    }
    int dfs(vector<vector<int>>& grid,vector<vector<bool>>&vis,int m,int n,int x,int y){
        int cnt = grid[x][y];
        int dr[] = {-1,1,0,0};
        int dc[] = {0,0,-1,1};
        for(int i=0;i<4;i++){
            int nr = x + dr[i];
            int nc = y + dc[i];
            if(isValid(nr,nc,m,n) && !vis[nr][nc] && grid[nr][nc]>0){
                vis[nr][nc] = true;
                cnt += dfs(grid,vis,m,n,nr,nc);
            }
        }
        return cnt;
    }
    int findMaxFish(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<bool>>vis(m,vector<bool>(n,false));
        int ans = 0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(!vis[i][j] && grid[i][j]>0){
                    vis[i][j] = true;
                    ans = max(ans,dfs(grid,vis,m,n,i,j));
                }
            }
        }
        return ans;
    }
};