class Spreadsheet {
private:
    int fun(string& s) {
        int x = 0;
        if (s[0] >= 'A' && s[0] <= 'Z') {
            int col = s[0] - 'A';
            int row = stoi(s.substr(1)) - 1;
            x = grid[row][col];
        } else {
            x = stoi(s);
        }
        return x;
    }

public:
    vector<vector<int>> grid;
    Spreadsheet(int rows) { grid.assign(rows, vector<int>(26, 0)); }

    void setCell(string cell, int value) {
        int col = cell[0] - 'A';
        int row = stoi(cell.substr(1)) - 1;
        grid[row][col] = value;
    }

    void resetCell(string cell) {
        int col = cell[0] - 'A';
        int row = stoi(cell.substr(1)) - 1;
        grid[row][col] = 0;
    }

    int getValue(string formula) {
        string s = formula.substr(1);
        int plusIdx = s.find('+');
        string left = s.substr(0, plusIdx);
        string right = s.substr(plusIdx + 1);
        return fun(left) + fun(right);
    }
};

/**
 * Your Spreadsheet object will be instantiated and called as such:
 * Spreadsheet* obj = new Spreadsheet(rows);
 * obj->setCell(cell,value);
 * obj->resetCell(cell);
 * int param_3 = obj->getValue(formula);
 */