class Solution {
public:
    double solve(double x, long long n) {
        if (n == 0)
            return 1;
        double t = solve(x, n / 2);
        if (n % 2 == 1)
            return t * t * x;
        return t * t;
    }
    double myPow(double x, int n) {
        long long N = n;
        return (N < 0) ? solve(1 / x, -N) : solve(x, N);
    }
};
