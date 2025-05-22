class Solution {
public:
    int maxRemoval(vector<int>& nums, vector<vector<int>>& q) {
        int n = nums.size();
        sort(q.begin(), q.end());
        priority_queue<int, vector<int>, greater<int>> used; // minHeap;
        priority_queue<int> avalible;                        // maxHeap;
        int j = 0;
        int ans = 0;
        for (int i = 0; i < n; i++) {

            while (j < q.size() && q[j][0] == i) {
                avalible.push(q[j][1]);
                j++;
            }

            nums[i] -= used.size();

            while (nums[i] > 0 && avalible.size() > 0 && avalible.top() >= i) {
                used.push(avalible.top());
                avalible.pop();
                nums[i]--;
                ans++;
            }

            if (nums[i] > 0)
                return -1;

            while (used.size() > 0 && used.top() == i) {
                used.pop();
            }
        }
        return q.size() - ans;
    }
};