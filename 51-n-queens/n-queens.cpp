class Solution {
public:
    // bool isSafe(int row,int col,vector<string>&ds,int n){
    //     int duprow=row;
    //     int dupcol=col;
    //     while(row>=0&&col>=0){
    //        if(ds[row][col]=='Q') return false;
    //        row--;
    //        col--;
    //     }
    //     row=duprow;
    //     col=dupcol;
    //      while(col>=0){
    //        if(ds[row][col]=='Q') return false;
    //        col--;
    //     }
    //       row=duprow;
    //     col=dupcol;
    //     while(row<n&&col>=0){
    //          if(ds[row][col]=='Q') return false;
    //        col--;
    //        row++;
    //     }
    //     return true;
    // }
    void fillQueen(int col, int n, vector<vector<string>>& ans,
                   vector<string>& ds, vector<int>& leftRow,
                   vector<int>& upperDio, vector<int>& lowerDio) {
        if (col == n) {
            ans.push_back(ds);
            return;
        }
        for (int row = 0; row < n; row++) {
            if (leftRow[row] == 0 && upperDio[n - 1 - row + col] == 0 &&
                lowerDio[row + col] == 0) {

                ds[row][col] = 'Q';
                leftRow[row] = 1;
                lowerDio[row + col] = 1;
                upperDio[n - 1 - row + col] = 1;
                fillQueen(col + 1, n, ans, ds, leftRow, upperDio, lowerDio);
                ds[row][col] = '.';
                leftRow[row] = 0;
                lowerDio[row + col] = 0;
                upperDio[n - 1 - row + col] = 0;
            }
        } 
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<string> ds(n);
        vector<vector<string>> ans;
        // string s(n,'.');
        for (int i = 0; i < n; i++) {
            ds[i] = string(n, '.');
        }
        vector<int> leftRow(n, 0), upperDio(2 * n - 1, 0),
            lowerDio(2 * n - 1, 0);
        fillQueen(0, n, ans, ds, leftRow, upperDio, lowerDio);
        return ans;
    }
};