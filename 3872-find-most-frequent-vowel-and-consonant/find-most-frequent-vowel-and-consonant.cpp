class Solution {
private:
    bool isVowel(char c) {
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    }

public:
    int maxFreqSum(string s) {
        vector<int> freq(26);
        for (auto& it : s) {
            freq[it - 'a']++;
        }
        int vo = 0;
        int con = 0;
        for (int i = 0; i < 26; i++) {
            if (isVowel(i + 'a'))
                vo = max(vo, freq[i]);
            else
                con = max(con, freq[i]);
        }
        return vo + con;
    }
};