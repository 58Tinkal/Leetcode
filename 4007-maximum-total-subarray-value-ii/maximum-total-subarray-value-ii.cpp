
class SegmentTreeMax {
private:
    int n;
    vector<int> tree;

    // build function
    void build(vector<int>& arr, int idx, int l, int r) {
        if (l == r) {
            tree[idx] = arr[l];
            return;
        }
        int mid = (l + r) / 2;
        build(arr, 2 * idx + 1, l, mid);
        build(arr, 2 * idx + 2, mid + 1, r);
        tree[idx] = max(tree[2 * idx + 1], tree[2 * idx + 2]);
    }

    // query max in range [ql, qr]
    int query(int idx, int l, int r, int ql, int qr) {
        if (qr < l || ql > r)
            return INT_MIN; // outside range
        if (ql <= l && r <= qr)
            return tree[idx]; // fully inside
        int mid = (l + r) / 2;
        return max(query(2 * idx + 1, l, mid, ql, qr),
                   query(2 * idx + 2, mid + 1, r, ql, qr));
    }

    // update position pos with new value val
    void update(int idx, int l, int r, int pos, int val) {
        if (l == r) {
            tree[idx] = val;
            return;
        }
        int mid = (l + r) / 2;
        if (pos <= mid)
            update(2 * idx + 1, l, mid, pos, val);
        else
            update(2 * idx + 2, mid + 1, r, pos, val);

        tree[idx] = max(tree[2 * idx + 1], tree[2 * idx + 2]);
    }

public:
    SegmentTreeMax(vector<int>& arr) {
        n = arr.size();
        tree.resize(4 * n, INT_MIN);
        build(arr, 0, 0, n - 1);
    }

    int query(int l, int r) { return query(0, 0, n - 1, l, r); }

    void update(int pos, int val) { update(0, 0, n - 1, pos, val); }
};
class SegmentTreeMin {
private:
    int n;
    vector<int> tree; // segment tree array

    // build function
    void build(vector<int>& arr, int idx, int l, int r) {
        if (l == r) {
            tree[idx] = arr[l];
            return;
        }
        int mid = (l + r) / 2;
        build(arr, 2 * idx + 1, l, mid);
        build(arr, 2 * idx + 2, mid + 1, r);
        tree[idx] = min(tree[2 * idx + 1], tree[2 * idx + 2]);
    }

    // query min in range [ql, qr]
    int query(int idx, int l, int r, int ql, int qr) {
        if (qr < l || ql > r)
            return INT_MAX; // outside range
        if (ql <= l && r <= qr)
            return tree[idx]; // fully inside
        int mid = (l + r) / 2;
        return min(query(2 * idx + 1, l, mid, ql, qr),
                   query(2 * idx + 2, mid + 1, r, ql, qr));
    }

    // update position pos with new value val
    void update(int idx, int l, int r, int pos, int val) {
        if (l == r) {
            tree[idx] = val;
            return;
        }
        int mid = (l + r) / 2;
        if (pos <= mid)
            update(2 * idx + 1, l, mid, pos, val);
        else
            update(2 * idx + 2, mid + 1, r, pos, val);

        tree[idx] = min(tree[2 * idx + 1], tree[2 * idx + 2]);
    }

public:
    SegmentTreeMin(vector<int>& arr) {
        n = arr.size();
        tree.resize(4 * n, INT_MAX);
        build(arr, 0, 0, n - 1);
    }

    int query(int l, int r) { return query(0, 0, n - 1, l, r); }

    void update(int pos, int val) { update(0, 0, n - 1, pos, val); }
};
class Solution {
public:
    long long maxTotalValue(vector<int>& nums, int k) {
        int n = nums.size();
        SegmentTreeMin mini(nums);
        SegmentTreeMax maxi(nums);
        priority_queue<pair<int, pair<int, int>>> pq;
        for (int i = 0; i < n; i++) {
            int x = maxi.query(i, n - 1);
            int y = mini.query(i, n - 1);
            pq.push({x - y, {i, n - 1}});
        }
        long long ans = 0;
        while (!pq.empty() && k > 0) {
            auto it = pq.top();
            pq.pop();
            ans += it.first;
            int l = it.second.first;
            int r = it.second.second;
            if (l <= r - 1) {
                int x = maxi.query(l, r - 1);
                int y = mini.query(l, r - 1);
                pq.push({x - y, {l, r - 1}});
            }
            k--;
        }
        return ans;
    }
};