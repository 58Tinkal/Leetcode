class MedianFinder {
private:
    priority_queue<int> mx; // left part of array
    priority_queue<int, vector<int>, greater<int>> mn;

public:
    MedianFinder() {}

    void addNum(int num) {
        int n = mx.size();
        int m = mn.size();

        if (n == 0) {
            mx.push(num);
            return;
        }

        int x = mx.top();
        int y = m > 0 ? mn.top() : INT_MAX;

        if (num <= x) {
            if (n - 1 == m) {
                mn.push(x);
                mx.pop();
                mx.push(num);
            } else {
                mx.push(num);
            }
            return;
        }

        if (num > x && num <= y) {
            if (n - 1 == m) {
                mn.push(num);
            } else {
                mx.push(num);
            }
            return;
        }

        if (num > y) {
            if (n - 1 == m) {
                mn.push(num);
            } else {
                mx.push(y);
                mn.pop();
                mn.push(num);
            }
            return;
        }
    }

    double findMedian() {
        if (mx.size() == mn.size()) {
            return (mx.top() + mn.top()) / 2.0;
        }
        return mx.top();
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */