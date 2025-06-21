class Solution {
public:
    int minimumDeletions(string word, int k) {
        vector<int> freq(26, 0);
        for (char c : word) 
            freq[c - 'a']++;

        int maxf = 0;
        for (int f : freq)
            maxf = max(maxf, f);

        int best = word.size();  // worst: delete everything

        // Try every possible lower‐bound L from 0 to maxf
        for (int L = 0; L <= maxf; ++L) {
            int U = L + k;
            int cost = 0;
            for (int f : freq) {
                if (f > U) {
                    cost += f - U;    // truncate down to U
                } else if (f < L) {
                    cost += f;        // delete entirely
                }
                // else keep f unchanged
            }
            best = min(best, cost);
        }

        return best;
    }
};
