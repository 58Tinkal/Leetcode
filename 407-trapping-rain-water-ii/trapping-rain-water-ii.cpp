class Solution {
public:
    bool isValid(int r, int c, int m, int n){
        return r>=0 && r<m && c>=0 && c<n;
    }
    int trapRainWater(vector<vector<int>>& heightMap) {
        int ans = 0;
        int m = heightMap.size();
        int n = heightMap[0].size();
        if(m<3 || n<3)  return ans;
        priority_queue<pair<int, pair<int, int>>,vector<pair<int, pair<int, int>>>,greater<pair<int, pair<int, int>>>>pq;
        vector<vector<bool>>vis(m,vector<bool>(n,false));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(i==0 || i==m-1 || j==0 || j==n-1){
                    pq.push({heightMap[i][j],{i,j}});
                    vis[i][j] = true;
                }
            }
        }
        int dr[] = {0,0,1,-1};
        int dc[] = {1,-1,0,0};
        int level = 0;
        while(!pq.empty()){
            auto it = pq.top();
            pq.pop();
            int height = it.first;
            int r = it.second.first;
            int c = it.second.second;
            level = max(level,height);
            for(int i=0;i<4;i++){
                int nr = r + dr[i];
                int nc = c + dc[i];
                if(isValid(nr,nc,m,n) && !vis[nr][nc]){
                    vis[nr][nc] = true;
                    pq.push({heightMap[nr][nc],{nr,nc}});
                    if(level > heightMap[nr][nc]){
                        ans += level - heightMap[nr][nc];
                    }
                }
            }
        }
        return  ans;
    }
};