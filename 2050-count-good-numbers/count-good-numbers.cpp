class Solution {
public:
    long long mod = 1e9 + 7;
    long long modPow(long long x, long long n, long long mod) {
        long long result = 1;
        x = x % mod;
        while (n > 0) {
            if (n & 1)
                result = (result * x) % mod;
            x = (x * x) % mod;
            n /= 2;
        }
        return result;
    }
    long long mulmod(long long a, long long b, long long mod) {
        long long result = 0;
        a = a % mod;

        while (b > 0) {
            if (b & 1)
                result = (result + a) % mod;
            a = (2 * a) % mod;
            b >>= 1;
        }

        return result;
    }
    int countGoodNumbers(long long n) {
        long long ans = 0;
        if (n % 2 == 0) {
            ans = (ans +
                   mulmod(modPow(5, n / 2, mod), modPow(4, n / 2, mod), mod)) %
                  mod;
        } else {
            if (n == 1) {
                return 5;
            }
            ans = (ans + mulmod(modPow(5, n / 2 + 1, mod),
                                modPow(4, n / 2, mod), mod)) %
                  mod;
        }
        return (int)ans;
    }
};