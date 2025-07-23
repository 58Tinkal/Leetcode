class Solution {
public:
    int remove(string &s, char a, char b, int value) {
        string temp;
        int gain = 0;
        for (char ch : s) {
            if (!temp.empty() && temp.back() == a && ch == b) {
                temp.pop_back();
                gain += value;
            } else {
                temp.push_back(ch);
            }
        }
        s = temp; // Efficient reassignment
        return gain;
    }

    int maximumGain(string s, int x, int y) {
        int total = 0;

        if (x > y) {
            total += remove(s, 'a', 'b', x);
            total += remove(s, 'b', 'a', y);  
        } else {
            total += remove(s, 'b', 'a', y); 
            total += remove(s, 'a', 'b', x);  
        }

        return total;
    }
};
