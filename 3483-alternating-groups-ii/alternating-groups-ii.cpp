class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors, int k) {
        int n = colors.size();
        if (k == 1) return n; 
 
        vector<int> diff(n);
        for (int i = 0; i < n; i++) {
            diff[i] = (colors[i] != colors[(i + 1) % n]) ? 1 : 0;
        }
        
        vector<int> diff_d(2 * n);
        for (int i = 0; i < 2 * n; i++) {
            diff_d[i] = diff[i % n];
        }
        
        int windowSize = k - 1;
        int sum = 0;
        
       
        for (int i = 0; i < windowSize; i++) {
            sum += diff_d[i];
        }
        
        int count = 0;
      
        if (sum == windowSize) count++;
    
        for (int i = 1; i < n; i++) {
            sum = sum - diff_d[i - 1] + diff_d[i + windowSize - 1];
            if (sum == windowSize) count++;
        }
        
        return count;
    }
};