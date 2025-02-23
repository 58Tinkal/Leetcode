class Solution {
public:
    long long maxSum(vector<vector<int>>& grid, vector<int>& limits, int k) {
        priority_queue<int>q;
        int n = grid.size();
        int m = grid[0].size();
        for(int i=0;i<n;i++){
            sort(grid[i].begin(),grid[i].end(),greater<int>());
            for(int j=0;j<m&&j<limits[i];j++){
                q.push(grid[i][j]);
            }
        }
        long long ans = 0;
        while(!q.empty() && k>0){
            ans+=q.top();
            q.pop();
            k--;
        }
        return ans;
    }
};