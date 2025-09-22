class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        vector<int> freq(101, 0); 
        for (int x : nums)
            freq[x]++;

        int maxFreq =
            *max_element(freq.begin(), freq.end()); 
        int total = 0;
        for (int f : freq) {
            if (f == maxFreq)
                total += f; 
        }
        return total;
    }
};
