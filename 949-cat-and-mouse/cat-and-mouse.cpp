class Solution {
public:
    int n;
    vector<vector<vector<int>>> dp;
    int fun(int m, int c, int move, vector<vector<int>>& graph) {
        if (move > 10 * n )
            return 0;

        if (m == 0)
            return 1;
        if (m == c)
            return 2;

        if (dp[m][c][move] != -1)
            return dp[m][c][move];

        // mouse turn
        if (move % 2 == 0) {
            bool draw = 0;
            for (auto it : graph[m]) {
                int ans = fun(it, c, move + 1, graph);
                if (ans == 1) {
                    return dp[m][c][move] = 1;
                }
                if (ans == 0) {
                    draw = true;
                }
            }
            if (draw)
                return dp[m][c][move] = 0;
            else
                return dp[m][c][move] = 2;
        } else {
            // cat turn
            bool draw = 0;
            for (auto it : graph[c]) {
                if (it == 0)
                    continue;
                int ans = fun(m, it, move + 1, graph);
                if (ans == 2) {
                    return dp[m][c][move] = 2;
                }
                if (ans == 0) {
                    draw = true;
                }
            }
            if (draw)
                return dp[m][c][move] = 0;
            else
                return dp[m][c][move] = 1;
        }
    }
    int catMouseGame(vector<vector<int>>& graph) {
        this->n = graph.size();
        dp = vector<vector<vector<int>>>(
            n + 1, vector<vector<int>>(n + 1, vector<int>(10 * n  + 1, -1)));
        return fun(1, 2, 0, graph);
    }
};