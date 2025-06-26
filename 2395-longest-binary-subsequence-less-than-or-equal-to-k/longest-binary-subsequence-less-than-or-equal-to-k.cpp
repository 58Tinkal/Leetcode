class Solution {
public:
    int longestSubsequence(string s, int k) {
        long long value = 0;          // current value of the subsequence
        long long pow2  = 1;          // 2^0, 2^1, 2^2, ...
        int kept = 0;                 // length of subsequence we keep

        // go from the least-significant bit (right end) to the left
        for (int i = (int)s.size() - 1; i >= 0; --i) {
            if (s[i] == '0') {        // always safe: adds no value
                kept++;
            } else {
                if (value + pow2 <= k) {   // we can afford this ‘1’
                    value += pow2;
                    kept++;
                }
            }

            // update weight of next more-significant bit
            pow2 <<= 1;
            if (pow2 > k) {           // further bits are too costly
                pow2 = k + 1;         // sentinel: will fail future tests
            }
        }
        return kept;
    }
};
