class Solution {
public:
    bool fun(vector<int>& c, int m, long long k) {
        long long cnt = 0;  
        for (int i = 0; i < c.size(); i++) {
            if (c[i] < m) continue; 
            cnt += c[i] / m;
            if (cnt >= k) return true;  
        }
        return cnt >= k;
    }

    int maximumCandies(vector<int>& c, long long k) {
        int mx = *max_element(c.begin(), c.end());
        int s = 1, e = mx, ans = 0;
        
        while (s <= e) {
            int m = s + (e - s) / 2;
            if (fun(c, m, k)) {
                ans = m;
                s = m + 1;
            } else {
                e = m - 1;
            }
        }
        return ans;
    }
};