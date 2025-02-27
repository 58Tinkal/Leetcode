class Solution {
public:
    int lenLongestFibSubseq(vector<int>& arr) {
        int n = arr.size();
        set<int> s(arr.begin(), arr.end());
        int ans = 0;
        for (int i = 0; i < n - 1; i++) {
            for (int j = i + 1; j < n; j++) {
                int a = arr[i];
                int b = arr[j];
                int res = 2;
                while ((s.find(a + b) != s.end())) {
                    res++;
                    int t = b;
                    b += a;
                    a = t;
                }
                if(res == 2) continue;
                else ans=max(ans,res);
            }
        }
        return ans;
    }
};