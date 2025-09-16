#include <bits/stdc++.h>
using namespace std;

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
         
            if (areCoprime(nums[i], st.top())) {
                st.push(nums[i]);
                continue;
            }

            long long it = nums[i];

            while (!areCoprime(it, st.top())) {
                it = lcm(it, st.top());
                st.pop();
                if (st.empty()) {
                    st.push(it);
                    break;
                }
                if (areCoprime(it, st.top())) {
                    st.push(it);
                    break;
                }
            }
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
