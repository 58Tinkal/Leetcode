

class Spreadsheet {
private:
    int arr[26][1005]; // Assuming max 100 rows

public:
    Spreadsheet(int rows) { 
        for (int i = 0; i < 26; i++) 
            for (int j = 0; j < rows; j++) 
                arr[i][j] = 0; 
    }

    void setCell(string cell, int value) {
        int r = cell[0] - 'A';  // Convert 'A' to index 0
        int c = stoi(cell.substr(1)) - 1; // Convert column (1-based) to 0-based index
        arr[r][c] = value;
    }

    void resetCell(string cell) {
        int r = cell[0] - 'A';
        int c = stoi(cell.substr(1)) - 1;
        arr[r][c] = 0;
    }

    int getValue(string f) {
        int x = 0, y = 0;
        int i = 1;
        string s = "";

        while (i < f.size() && f[i] != '+') {
            s += f[i];
            i++;
        }

        if (s[0] >= 'A' && s[0] <= 'Z') {
            int r = s[0] - 'A';
            int c = stoi(s.substr(1)) - 1;
            x = arr[r][c];
        } else {
            x = stoi(s);
        }

        i++; // Move past '+'
        s = "";
        while (i < f.size()) {
            s += f[i];
            i++;
        }

        if (s[0] >= 'A' && s[0] <= 'Z') {
            int r = s[0] - 'A';
            int c = stoi(s.substr(1)) - 1;
            y = arr[r][c];
        } else {
            y = stoi(s);
        }

        return x + y;
    }
};

/**
 * Example usage:
 * Spreadsheet* obj = new Spreadsheet(100);
 * obj->setCell("A1", 5);
 * obj->setCell("B2", 10);
 * cout << obj->getValue("A1+B2"); // Should return 15
 */
