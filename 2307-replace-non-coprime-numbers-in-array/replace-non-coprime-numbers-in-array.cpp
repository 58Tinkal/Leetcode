class Solution {
private:
    bool areCoprime(long long a, long long b) { 
        return std::gcd(a, b) == 1; 
    }

    long long lcm(long long a, long long b) { 
        return (a / std::gcd(a, b)) * b; 
    }

public:
    vector<int> replaceNonCoprimes(vector<int>& nums) {
        stack<long long> st;
        st.push(nums[0]);
        int n = nums.size();

        for (int i = 1; i < n; i++) {
            long long it = nums[i];

            while (!st.empty() && !areCoprime(it, st.top())) {
                it = lcm(it, st.top());
                st.pop();
            }
            st.push(it);
        }

        vector<int> ans;
        while (!st.empty()) {
            ans.push_back((int)st.top());
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
