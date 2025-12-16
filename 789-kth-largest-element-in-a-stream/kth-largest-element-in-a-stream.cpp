class KthLargest {
public:
    priority_queue<int, vector<int>, greater<int>> pq;
    vector<int> a;
    int k;
    KthLargest(int k, vector<int>& nums) {
        a = nums;
        this->k = k;
        for (auto& val : nums) {
            if (pq.size() == k) {
                if (pq.top() < val) {
                    pq.pop();
                    pq.push(val);
                }
            } else {
                pq.push(val);
            }
        }
    }

    int add(int val) {
        if (pq.size() == k) {
            if (pq.top() < val) {
                pq.pop();
                pq.push(val);
            }
        } else {
            pq.push(val);
        }
        return pq.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */