class Solution {
private:
    bool isZero(int a) {
        while (a > 0) {
            int d = a % 10;
            a = a / 10;
            if (d == 0)
                return true;
        }
        return false;
    }

public:
    vector<int> getNoZeroIntegers(int n) {
        for (int i = 1; i < n; i++) {
            int a = i;
            int b = n - i;
            if (isZero(a) == false && isZero(b) == false) {
                return {a, b};
            }
        }
        return {};
    }
};