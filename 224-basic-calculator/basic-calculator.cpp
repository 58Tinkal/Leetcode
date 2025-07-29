class Solution {
public:
    int calculate(string s) {
        int n = s.length();
        stack<int> nums;
        stack<int> ops;
        int num = 0, res = 0, sign = 1;

        for (int i = 0; i < n; ++i) {
            char ch = s[i];

            if (isdigit(ch)) {
                num = ch - '0';
                while (i + 1 < n && isdigit(s[i + 1])) {
                    num = num * 10 + (s[++i] - '0');
                }
                res += sign * num;
            }
            else if (ch == '+') {
                sign = 1;
            }
            else if (ch == '-') {
                sign = -1;
            }
            else if (ch == '(') {
                nums.push(res);
                ops.push(sign);
                res = 0;
                sign = 1;
            }
            else if (ch == ')') {
                res = nums.top() + ops.top() * res;
                nums.pop();
                ops.pop();
            }
        }

        return res;
    }
};
