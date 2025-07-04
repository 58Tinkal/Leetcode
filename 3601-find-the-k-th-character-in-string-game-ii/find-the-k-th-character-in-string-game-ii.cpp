class Solution {
public:
    char kthCharacter(long long k, vector<int>& operations) {
        long long op = 0;
        long long val = k;
        while (val > 1) {
            long long jump = ceil(log2(val));
            val -= pow(2, jump - 1);
            op += operations[jump - 1];
        }
        return char('a' + (op) % 26);
    }
};