class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<int>a1(m),a2(n);
        int server = 0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j] == 0) continue;
                server++;
                a1[i]++; a2[j]++;
            }
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j] == 0) continue;
                if(a1[i] < 2 && a2[j] <2) server--;
            }
        }
        return server;
    }
};