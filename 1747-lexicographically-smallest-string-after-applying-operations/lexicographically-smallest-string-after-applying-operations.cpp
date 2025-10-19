class Solution {
public:
    string smallest;

    void rotate(string& s, int b) {
        reverse(s.begin(), s.end());
        reverse(s.begin(), s.begin() + b);
        reverse(s.begin() + b, s.end());
    }

    void dfs(string s, int a, int b, unordered_set<string>& vis) {
        if (vis.count(s))
            return;
        vis.insert(s);
        if (s < smallest)
            smallest = s;

        string temp = s;
        for (int i = 1; i < temp.size(); i += 2)
            temp[i] = ((temp[i] - '0' + a) % 10) + '0';
        dfs(temp, a, b, vis);

        string rotated = s;
        rotate(rotated, b);
        dfs(rotated, a, b, vis);
    }

    string findLexSmallestString(string s, int a, int b) {
        unordered_set<string> vis;
        smallest = s;
        dfs(s, a, b, vis);
        return smallest;
    }
};
