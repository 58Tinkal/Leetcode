class Solution {
public:
    bool isDigit(char c) { return c >= '0' && c <= '9'; }
    int operation(int x, int y, char exp) {
        if (exp == '+')
            return x + y;
        if (exp == '-')
            return x - y;
        if (exp == '*')
            return x * y;
        return 0;
    }
    vector<int> diffWaysToCompute(string exp) {
        vector<int> ans;
        bool f = true;
        for (int i = 0; i < exp.size(); i++) {
            if (!isDigit(exp[i])) {
                f = false;
                vector<int> left = diffWaysToCompute(exp.substr(0, i));
                vector<int> right = diffWaysToCompute(exp.substr(i + 1));

                for (auto x : left) {
                    for (auto y : right) {
                        int val = operation(x, y, exp[i]);
                        ans.push_back(val);
                    }
                }
            }
        }
        if (f)
            ans.push_back(stoi(exp));

        return ans;
    }
};