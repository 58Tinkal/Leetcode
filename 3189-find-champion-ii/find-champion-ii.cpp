class Solution {
public:
    int findChampion(int n, vector<vector<int>>& edges) {
        vector<int> inDegree(n, 0);
        for (auto it : edges) {
            inDegree[it[1]]++;
        }
        int x = -1;
        for (int i = 0; i < n; i++) {
            if (inDegree[i] == 0) {
                if (x == -1) {
                    x = i;
                } else if (x != -1) {
                    return -1;
                }
            }
        }
        return x;
    }
};