#define ll long long
class Solution {
    ll k_palindromes = 0;
    unordered_set<ll> done;
    vector<ll> fact;

    void precomputeFactorial(int n) {
        fact.resize(n + 1);
        fact[0] = 1;
        for (int i = 1; i <= n; ++i)
            fact[i] = i * fact[i - 1];
    }

    ll countAllPermutations(vector<ll>& freq, int n) {
        ll count = fact[n];
        for (int i = 0; i <= 9; ++i)
            count /= fact[freq[i]];
        return count;
    }

    ll allArrangements(const string& number, int n) {
        string sorted_number = number;
        if (sorted_number.find(' ') != string::npos) return 0; // Invalid number
        sort(sorted_number.begin(), sorted_number.end());

        ll num = stoll(sorted_number);
        if (done.count(num))
            return 0;

        done.insert(num);
        vector<ll> freq(10);
        for (char c : sorted_number)
            freq[c - '0']++;

        ll total = countAllPermutations(freq, n);
        ll invalid = 0;
        if (freq[0] > 0) {
            freq[0]--;
            invalid = countAllPermutations(freq, n - 1);
        }
        return total - invalid;
    }

    bool isKPalindrome(const string& number, int k) {
        if (number.find(' ') != string::npos) return false; // Incomplete number
        ll num = stoll(number);
        return (num % k == 0);
    }

    void generatePalindromes(int pos, int n, string& number, int k) {
        if (pos >= (n + 1) / 2) {
            if (isKPalindrome(number, k))
                k_palindromes += allArrangements(number, n);
            return;
        }

        for (char ch = (pos == 0 ? '1' : '0'); ch <= '9'; ++ch) {
            number[pos] = number[n - pos - 1] = ch;
            generatePalindromes(pos + 1, n, number, k);
        }
    }

public:
    long long countGoodIntegers(int n, int k) {
        k_palindromes = 0;
        done.clear();
        fact.clear();
        precomputeFactorial(n);

        string number(n, ' ');
        generatePalindromes(0, n, number, k);

        return k_palindromes;
    }
};
