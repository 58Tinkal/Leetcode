class Solution {
public:
    // next smaller element
    vector<int> nse(vector<int>& arr) {
        int n = arr.size();
        vector<int> nseEl(n);
        stack<int> st;
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && arr[st.top()] >= arr[i])
                st.pop();
            nseEl[i] = (st.empty()) ? n : st.top();
            st.push(i);
        }
        return nseEl;
    }
    // next greater element
    vector<int> nge(vector<int>& arr) {
        int n = arr.size();
        vector<int> temp(n);
        stack<int> st;
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && arr[st.top()] <= arr[i])
                st.pop();
            temp[i] = (st.empty()) ? n : st.top();
            st.push(i);
        }
        return temp;
    }
    // previous smaller and equal element
    vector<int> psee(vector<int>& arr) {
        int n = arr.size();
        vector<int> pseeEl(n);
        stack<int> st;
        for (int i = 0; i < n; i++) {
            while (!st.empty() && arr[st.top()] > arr[i])
                st.pop();
            pseeEl[i] = (st.empty()) ? -1 : st.top();
            st.push(i);
        }
        return pseeEl;
    }
    // previous greater and equal element
    vector<int> pgee(vector<int>& arr) {
        int n = arr.size();
        stack<int> st;
        vector<int> temp(n);
        for (int i = 0; i < n; i++) {
            while (!st.empty() && arr[st.top()] < arr[i])
                st.pop();
            temp[i] = (st.empty()) ? -1 : st.top();
            st.push(i);
        }
        return temp;
    }
    long long subArrayRanges(vector<int>& nums) {
        int n = nums.size();
        vector<int> ngE = nge(nums);
        vector<int> nsE = nse(nums);
        vector<int> pgeE = pgee(nums);
        vector<int> pseE = psee(nums);
        long long s = 0;
        for (int i = 0; i < n; i++) {
            int l = i - pseE[i];
            int r = nsE[i] - i;
            int L = i - pgeE[i];
            int R = ngE[i] - i;
            s += (long long)L * R * nums[i] - (long long)l * r * nums[i];
        }
        return s;
    }
};