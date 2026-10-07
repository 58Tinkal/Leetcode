class Solution {
public:
    map<int, vector<string>> m;
    int max_remove = INT_MAX;

    void fun(int idx, string& str, string& s, int remove, int dif) {

        if (dif < 0)
            return;

        if (idx == s.size()) {
            if (dif != 0)
                return;

            if (remove < max_remove) {
                max_remove = remove;
                m.clear();
                m[remove].push_back(str);
            }
            else if (remove == max_remove) {
                m[remove].push_back(str);
            }

            return;
        }

        // Do not delete
        str.push_back(s[idx]);

        if (s[idx] == '(') {
            fun(idx + 1, str, s, remove, dif + 1);
        }
        else if (s[idx] == ')') {
            fun(idx + 1, str, s, remove, dif - 1);
        }
        else {
            fun(idx + 1, str, s, remove, dif);
        }

        // Backtrack
        str.pop_back();

        // Delete
        fun(idx + 1, str, s, remove + 1, dif);
    }

    vector<string> removeInvalidParentheses(string s) {

        string str = "";

        fun(0, str, s, 0, 0);

        set<string> unique;

        for (auto& it : m) {
            for (auto& x : it.second) {
                unique.insert(x);
            }
        }

        return vector<string>(unique.begin(), unique.end());
    }
};