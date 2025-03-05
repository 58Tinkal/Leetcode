class Solution {
public:
    long long coloredCells(int n) {
        long long x = 5;
        if(n==1) {
            return 1;
        }
        if(n==2)  return 5;
        long long p=8;
        for(int i=3;i<=n;i++){
            x+=p;
            p+=4;
        }
        cout<<x<<endl;
        return x;
    }
};