class Solution {
public:
    bool checkDivisibility(int n) {
        int x = n;
        int d = 0;
        int p = 1;
        while(x != 0){
            d += (x%10);
            p = p*(x%10);
            x = x/10;
        }
        cout<<p<<' '<<d<<endl;
        return n%(p+d) == 0;
    }
};

