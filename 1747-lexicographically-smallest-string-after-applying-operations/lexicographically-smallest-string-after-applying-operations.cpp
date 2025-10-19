class Solution {
public:
    void rotate(string& s, int b) {
        reverse(s.begin(), s.end());
        reverse(s.begin(), s.begin() + b);
        reverse(s.begin() + b, s.end());
    }
    string findLexSmallestString(string s, int a, int b) {
        string smallest = s;
        queue<string> q;
        unordered_set<string> vis;
        q.push(s);
        vis.insert(s);
        while (!q.empty()) {
            string str = q.front();
            q.pop();
            if (str < smallest) {
                smallest = str;
            }
            string temp = str;
            for (int i = 1; i < temp.size(); i += 2) {
                temp[i] = ((temp[i] - '0' + a) % 10) + '0';
            }
            if (!vis.count(temp)) {
                q.push(temp);
                vis.insert(temp);
            }
            rotate(str, b);

            if (!vis.count(str)) {
                q.push(str);
                vis.insert(str);
            }
        }
        return smallest;
    }
};