class Solution {
public:
    bool fun(vector<int>& nums, vector<vector<int>>& q, int m) {
        int n = nums.size();
        vector<int> a(n, 0); 

        for (int i = 0; i < m; i++) {  
            int l = q[i][0];
            int r = q[i][1];
            int v = q[i][2];

            a[l] += v;
            if (r + 1 < n)
                a[r + 1] -= v;
        }
        for (int i = 1; i < n; i++) {  
            a[i] += a[i - 1];
        }
        for (int i = 0; i < n; i++) {
            if (a[i] < nums[i])
                return false;
        }
        return true;
    }

    int minZeroArray(vector<int>& nums, vector<vector<int>>& q) {
        int l = 1;
        int h = q.size() ; 
        int ans = -1; 
        bool f = true;
        for(int i=0;i<nums.size();i++){
            if(nums[i] != 0) f = false;
        }
        if(f) return 0;
        while (l <= h) {
            int m = (l + h) / 2;
            if (fun(nums, q, m)) {
                ans = m;
                h = m - 1;  
            } else {
                l = m + 1;
            }
        }
        return ans;
    }
};
