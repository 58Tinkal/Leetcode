class Solution {
private:
    vector<bool> sieve(int n) {
        vector<bool> is_prime(n + 1, true);
        is_prime[0] = is_prime[1] = false;
        for (int i = 2; i * i <= n; i++) {
            if (is_prime[i]) {
                for (int j = i * i; j <= n; j += i) {
                    is_prime[j] = false;
                }
            }
        }
        return is_prime;
    }

public:
    int minOperations(int n, int m) {
        vector<bool> prime = sieve(10000);

        if (prime[n] || prime[m])
            return -1;

        priority_queue<pair<int, int>, vector<pair<int, int>>,
                       greater<pair<int, int>>>
            q;
        q.push({n, n});

        unordered_set<int> vis;
        while (!q.empty()) {
            auto [val, node] = q.top();
            q.pop();

            if (vis.count(node))
                continue;
            vis.insert(node);

            if (node == m)
                return val;

            string S = to_string(node);
            for (int i = 0; i < S.size(); i++) {
                char original = S[i];

                // Increment the digit
                if (S[i] < '9') {
                    S[i]++;
                    int num = stoi(S);
                    if (num <= 10000 && !prime[num] && !vis.count(num)) {
                        q.push({val + num, num});
                    }
                    S[i] = original;
                }

                // Decrement the digit
                if (S[i] > '0') {
                    S[i]--;
                    int num = stoi(S);
                    if (num > 0 && num <= 10000 && !prime[num] &&
                        !vis.count(num)) {
                        q.push({val + num, num});
                    }
                    S[i] = original;
                }
            }
        }
        return -1;
    }
};
