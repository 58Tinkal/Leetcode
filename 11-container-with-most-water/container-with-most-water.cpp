class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int i = 0;
        int j = n - 1;
        int ans = INT_MIN;
        while (i < j) {
            int length = j - i;
            int width = min(height[i], height[j]);
            ans = max(ans, length * width);
            if (height[i] > height[j]) {
                j--;
            } else {
                i++;
            }
        }
        return ans;
    }
};