class Solution {
#define pci pair<char, int>
    int isVowel(const char& c) {
        return (c == 'A' or c == 'a' or c == 'E' or c == 'e' or c == 'I' or
                c == 'i' or c == 'O' or c == 'o' or c == 'U' or c == 'u');
    }

public:
    string sortVowels(string s) {
        int n = s.size();

        map<char, int> vowel_freq;
        for (int i = 0; i < n; ++i) {
            if (isVowel(s[i]))
                vowel_freq[s[i]]++;
        }

        vector<pci> freq;
        for (pair vf : vowel_freq)
            freq.push_back(vf);

        int pos = 0;
        int i = 0;
        while (i < n and pos < freq.size()) {
            if (freq[pos].second == 0) {
                pos++;
                continue;
            }
            if (isVowel(s[i])) {
                s[i] = freq[pos].first;
                freq[pos].second--;
            }
            i++;
        }
        return s;
    }
};