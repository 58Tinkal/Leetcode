class Solution {
private:
    string toLowerCase(const string& s) {
        string result = s;
        transform(result.begin(), result.end(), result.begin(),
                  [](unsigned char c) { return tolower(c); });
        return result;
    }

private:
    bool isVowel(char& c) {
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    }

public:
    vector<string> spellchecker(vector<string>& wordlist,
                                vector<string>& queries) {
        unordered_set<string> exactWords(wordlist.begin(), wordlist.end());
        unordered_map<string, string> caseMap;
        for (auto& it : wordlist) {
            string st = toLowerCase(it);
            if (caseMap.find(st) != caseMap.end())
                continue;
            caseMap[st] = it;
        }
        unordered_map<string, string> vowelMap;
        for (auto& it : wordlist) {
            string st = toLowerCase(it);
            for (auto& itt : st) {
                if (isVowel(itt)) {
                    itt = '*';
                }
            }
            if (vowelMap.find(st) != vowelMap.end())
                continue;
            vowelMap[st] = it;
        }
        vector<string> ans;
        for (auto& it : queries) {

            if (exactWords.find(it) != exactWords.end()) {
                ans.push_back(it);
                continue;
            }
            string st = toLowerCase(it);
            if (caseMap.find(st) != caseMap.end()) {
                ans.push_back(caseMap[st]);
                continue;
            }
            for (auto& itt : st) {
                if (isVowel(itt)) {
                    itt = '*';
                }
            }
            if (vowelMap.find(st) != vowelMap.end()) {
                ans.push_back(vowelMap[st]);
                continue;
            }
            ans.push_back("");
        }
        return ans;
    }
};