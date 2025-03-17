class Solution {
public:
    bool divideArray(vector<int>& nums) {
        int freq[501] = {0};
        for (auto& it : nums)
            freq[it]++;
        for (int i = 1; i <= 500; i++)
            if (freq[i] % 2 == 1)
                return false;
        return true;
    }
};