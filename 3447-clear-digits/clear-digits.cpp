class Solution {
public:
    string clearDigits(string s) {
        stack<char> st;
        for (char c : s) {
            if (c >= '0' && c <= '9') { 
                if (!st.empty() && st.top() >= 'a' && st.top() <= 'z') {
                    st.pop(); 
                }
            } else {
                st.push(c);
            }
        }
        string str = "";
        while (!st.empty()) {
            str.push_back(st.top());
            st.pop();
        }
        reverse(str.begin(), str.end());
        return str;
    }
};
