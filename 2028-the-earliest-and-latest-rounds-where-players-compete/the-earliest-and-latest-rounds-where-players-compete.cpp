class Solution {
public:
    int n;
    int min_round = INT_MAX;
    int max_round = INT_MIN;
    void solve(int mask, int left, int right, int p1, int p2, int round){
        if(left >= right){
            solve(mask,0,n-1,p1,p2,round+1);
        }else if((mask&(1<<left)) == 0){
              solve(mask,left+1,right,p1,p2,round);
        }else if((mask&(1<<right)) == 0){
              solve(mask,left,right-1,p1,p2,round);
        }else if(left == p1 && right == p2){
            min_round = min(min_round, round);
            max_round = max(max_round, round);
        }else{
            if(left != p1 && left != p2){
                solve(mask^(1<<left),left+1,right-1,p1,p2,round);
            }
            if(right != p1 && right != p2){
                solve(mask^(1<<right),left+1,right-1,p1,p2,round);
            }
        }
    }
    vector<int> earliestAndLatest(int n, int fP, int sP) {
        this->n = n;
        fP--;  sP--;
        int mask = (1<<n) - 1;
        solve(mask,0,n-1,fP,sP,1);
        return {min_round, max_round};
    }
};