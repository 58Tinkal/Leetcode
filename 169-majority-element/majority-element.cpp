class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        int x;
        int c = 0;
        for (int i = 0; i < n; i++) {
            if (c == 0) {
                x = nums[i];
                c = 1;
            }
            else if (nums[i] == x)
                c++;
            else
                c--;
        }
        cout<<x<<endl;
        c = 0;
        for (int i = 0; i < n; i++) {
            if (nums[i] == x)
                c++;
        }
        if (c > n / 2)
            return x;
        return -1;
    }
};