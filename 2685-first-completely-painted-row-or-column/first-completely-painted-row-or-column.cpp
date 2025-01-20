class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        vector<pair<int,int>>pos(m*n+1);
        vector<int>row(n,0),col(m,0);
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                pos[mat[i][j]] = make_pair(i,j);
            }
        }
        for(int i=0;i<arr.size();i++){
            auto it = pos[arr[i]];
            row[it.second]++;
            col[it.first]++;
            if(row[it.second] == m || col[it.first] == n) return i; 
        }
        return arr.size()-1;
    }
};