#define ll long long int
class SGTree {
    vector<ll> seg;

public:
    SGTree(ll n) { seg.resize(4 * n + 1); }

    void build(ll ind, ll low, ll high, ll idx) {
        if (high < idx || low > idx)
            return;
        if (low == high) {
            seg[ind]++;
            return;
        }

        ll mid = low + (high - low) / 2;
        build(2 * ind + 1, low, mid, idx);
        build(2 * ind + 2, mid + 1, high, idx);
        seg[ind] = (seg[2 * ind + 1] + seg[2 * ind + 2]);
    }

    ll query(ll ind, ll low, ll high, ll l, ll r) {
        // no overlap
        if (r < low || high < l)
            return 0;

        // complete overlap
        if (low >= l && high <= r)
            return seg[ind];

        ll mid = low + (high - low) / 2;
        ll left = query(2 * ind + 1, low, mid, l, r);
        ll right = query(2 * ind + 2, mid + 1, high, l, r);
        return (left + right);
    }
};

class Solution {
public:
    long long goodTriplets(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        SGTree sg(n);
        unordered_map<ll, ll> m;
        for (int i = 0; i < n; i++) {
            m[nums2[i]] = i;
        }
        sg.build(0, 0, n - 1, m[nums1[0]]);
        ll ans = 0;
        for (int i = 1; i < n - 1; i++) {
            ll k = m[nums1[i]];
            ll left = sg.query(0, 0, n - 1, 0, k);
            ll u_left = i - left;
            ll right = (n - k - 1) - u_left;
            ans += left * right;
            sg.build(0, 0, n - 1, k);
        }
        return ans;
    }
};