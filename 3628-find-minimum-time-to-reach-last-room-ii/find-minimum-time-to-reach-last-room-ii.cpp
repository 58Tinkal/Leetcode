class Solution {
const vector<pair<int, int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
public:
    int minTimeToReach(vector<vector<int>>& moveTime) {
        int n = moveTime.size();
        int m = moveTime[0].size();
        //distance from 0,0 to i,j
        vector<vector<int>> dist(n, vector<int>(m, INT_MAX));
        dist[0][0] = 0;
        
        //Priority Queue to maintain closest room we have not visited yet
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<>> pq;
        pq.push({0, 0, 0});
        while (!pq.empty()) {
            auto [currentDist, row, col] = pq.top();
            pq.pop();
            
            if (row == n - 1 && col == m - 1) {
                return currentDist;  
            }
            
            for (const auto& [dx, dy] : directions) {
                int newRow = row + dx;
                int newCol = col + dy;
                
                if (newRow >= 0 && newRow < n && newCol >= 0 && newCol < m) {
                    int travelTime = 2-(newRow+newCol)%2; // =(newRow+newCol)%2? 1:2;
                    
                    int newDist = max(currentDist, moveTime[newRow][newCol])+travelTime;
                    
                    if (newDist < dist[newRow][newCol]) {
                        dist[newRow][newCol] = newDist;
                        pq.push({newDist, newRow, newCol});
                    }
                }
            }
        }    
        return dist[n-1][m-1];
    }
};