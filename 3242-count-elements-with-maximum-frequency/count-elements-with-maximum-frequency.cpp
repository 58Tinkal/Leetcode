class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        vector<int> freq(101, 0);
        for (auto it : nums) {
            freq[it]++;
        }
        sort(freq.begin(), freq.end()); 
        int count = 0, x = freq[100];   
        for (int i = 100; i >= 0; i--) {
            if (freq[i] == x) {
                count += freq[i];
            } else
                break;
        }
        return count;
    }
};
