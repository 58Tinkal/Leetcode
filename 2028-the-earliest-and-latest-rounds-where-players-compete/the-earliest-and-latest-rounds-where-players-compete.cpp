class Solution {
public:
    int n;
    int min_round = INT_MAX;
    int max_round = INT_MIN;
    bool dp[28][28][28];
    // void solve(int mask, int left, int right, int p1, int p2, int round){
    //     if(left >= right){
    //         solve(mask,0,n-1,p1,p2,round+1);
    //     }else if((mask&(1<<left)) == 0){
    //           solve(mask,left+1,right,p1,p2,round);
    //     }else if((mask&(1<<right)) == 0){
    //           solve(mask,left,right-1,p1,p2,round);
    //     }else if(left == p1 && right == p2){
    //         min_round = min(min_round, round);
    //         max_round = max(max_round, round);
    //     }else{
    //         if(left != p1 && left != p2){
    //             solve(mask^(1<<left),left+1,right-1,p1,p2,round);
    //         }
    //         if(right != p1 && right != p2){
    //             solve(mask^(1<<right),left+1,right-1,p1,p2,round);
    //         }
    //     }
    // }
    void solve(int mask, int left, int right, int p1, int p2, int round, int l,
               int m, int r) {
        if (left >= right) {
            solve(mask, 0, n - 1, p1, p2, round + 1, l, m, r);
        } else if ((mask & (1 << left)) == 0) {
            solve(mask, left + 1, right, p1, p2, round, l, m, r);
        } else if ((mask & (1 << right)) == 0) {
            solve(mask, left, right - 1, p1, p2, round, l, m, r);
        } else if (left == p1 && right == p2) {
            min_round = min(min_round, round);
            max_round = max(max_round, round);
        } else if (!dp[l][m][r]) {
            dp[l][m][r] = true;
            if (left != p1 && left != p2) {
                solve(mask ^ (1 << left), left + 1, right - 1, p1, p2, round,
                      l - (left < p1), m - (left > p1 && left < p2),
                      r - (left > p2));
            }
            if (right != p1 && right != p2) {
                solve(mask ^ (1 << right), left + 1, right - 1, p1, p2, round,
                      l - (right < p1), m - (right > p1 && right < p2),
                      r - (right > p2));
            }
        }
    }
    vector<int> earliestAndLatest(int n, int fP, int sP) {
        this->n = n;
        fP--;
        sP--;
        int mask = (1 << n) - 1;
        memset(dp, false, sizeof(dp));
        solve(mask, 0, n - 1, fP, sP, 1, fP, sP - fP - 1, n - 1 - sP);
        return {min_round, max_round};
    }
};