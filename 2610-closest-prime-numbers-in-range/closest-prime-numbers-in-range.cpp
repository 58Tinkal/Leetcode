#define ll long long int
class Solution {
public:
    vector<int> sieve(ll n, int left, int right) {
        vector<bool> is_prime(n + 1, true);
        vector<int> primes;
        is_prime[0] = is_prime[1] = false;

        for (ll i = 2; i * i <= n; i++) {
            if (is_prime[i]) {
                for (ll j = i * i; j <= n; j += i) {
                    is_prime[j] = false;
                }
            }
        }

        for (ll i = left; i <= right; i++) {
            if (i <= n && is_prime[i]) { 
                primes.push_back(i);
            }
        }
        return primes;
    }

    vector<int> closestPrimes(int left, int right) {
        vector<int> p = sieve(1e6 + 7, left, right);

        if (p.size() < 2) return {-1, -1}; 

        int x = p[0], y = p[1];
        int mn = p[1] - p[0];

        for (int i = 1; i < p.size() - 1; i++) {
            if (mn > p[i + 1] - p[i]) {
                mn = p[i + 1] - p[i];
                x = p[i];
                y = p[i + 1];
            }
        }
        return {x, y};
    }
};
