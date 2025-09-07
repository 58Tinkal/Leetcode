class Solution {
private:
    void nger(vector<int>& arr, vector<int>& ng) {
        stack<int> st;
        int n = arr.size();
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && arr[st.top()] < arr[i])
                st.pop();
            ng[i] = st.empty() ? n : st.top();
            st.push(i);
        }
    }
    void ngel(vector<int>& arr, vector<int>& ng) {
        stack<int> st;
        int n = arr.size();
        for (int i = 0; i < n; i++) {
            while (!st.empty() && arr[st.top()] <= arr[i])
                st.pop();
            ng[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }
    }
    long long maxContribution(vector<int>& nums, int k) {
        long long ans = 0;
        int n = nums.size();
        vector<int> r(n);
        vector<int> l(n);
        nger(nums, r);
        ngel(nums, l);

        for (int i = 0; i < n; i++) {
            l[i] =
                max(l[i], i - k); // restricting left side so it not go beyong k
            r[i] = min(r[i], i + k); // restricting right side so it not go
                                     // beyond k as max size is k
            long long ld = i - l[i];
            long long rd = r[i] - i;
            long long mnd = min(ld, rd);
            long long mxd = max(ld, rd);

            ans += (mnd * (mnd + 1) / 2) * nums[i];
            ans += (min(mnd + mxd - 1, (long long)k) - mnd) * mnd * nums[i];
            long long diff = min(mxd + mnd - 1, (long long)k) - mxd;
            ans -= ((diff * (diff + 1)) / 2) * nums[i];
        }
        return ans;
    }

private:
    void nser(vector<int>& arr, vector<int>& ns) {
        stack<int> st;
        int n = arr.size();
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && arr[st.top()] > arr[i])
                st.pop();
            ns[i] = st.empty() ? n : st.top();
            st.push(i);
        }
    }
    void nsel(vector<int>& arr, vector<int>& ns) {
        stack<int> st;
        int n = arr.size();
        for (int i = 0; i < n; i++) {
            while (!st.empty() && arr[st.top()] >= arr[i])
                st.pop();
            ns[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }
    }
    long long minContribution(vector<int>& nums, int k) {
        long long ans = 0;
        int n = nums.size();
        vector<int> r(n);
        vector<int> l(n);
        nser(nums, r);
        nsel(nums, l);
        for (int i = 0; i < n; i++) {
            l[i] =
                max(l[i], i - k); // restricting left side so it not go beyong k
            r[i] = min(r[i], i + k); // restricting right side so it not go
                                     // beyond k as max size is k
            long long ld = i - l[i];
            long long rd = r[i] - i;
            long long mnd = min(ld, rd);
            long long mxd = max(ld, rd);

            ans += (mnd * (mnd + 1) / 2) * nums[i];
            ans += (min(mnd + mxd - 1, (long long)k) - mnd) * mnd * nums[i];
            long long diff = min(mxd + mnd - 1, (long long)k) - mxd;
            ans -= ((diff * (diff + 1)) / 2) * nums[i];
        }
        return ans;
    }

public:
    long long minMaxSubarraySum(vector<int>& nums, int k) {
        long long ans = 0;
        ans += maxContribution(nums, k);
        ans += minContribution(nums, k);
        return ans;
    }
};