class Solution {
public:
    long long maxWeight(vector<int>& a) {
        int n = a.size();
        sort(a.begin(), a.end(), greater<int>());

        // for(auto it& : a) cout << it << ' ';
        // cout << endl;

        int x = n / 4;
        long long ans = 0;
        int k = 0;

        for (int i = 0; k < x;) {
            ans += a[i];
            cout << a[i] << ' ';
            if (k % 2 == 0) i += 2;
            else i += 1;
            k++;
        }

        long long res = 0;
        int p = ceil(x / 2.0); 

        for (int i = 0; i < p; i++) {
            res += a[i];
        }

        int m = x / 2;
        for (int i = p+1; i < n && m > 0; i += 2) { 
            res += a[i];
            m--;
        }

        return max(ans, res);
    }
};
