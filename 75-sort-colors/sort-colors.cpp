class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        // making a non zero element to the right (i.e. zeros to the left)
        int i = -1;
        for (int j = 0; j < nums.size(); j++) {
            if (nums[j] != 0) {
                i = j;
                break;
            }
        }
        if(i==-1) return;
        for (int j = i + 1; j < n; j++) {
            if (nums[j] == 0) {
                swap(nums[i], nums[j]);
                i++;
            }
        }

        // making 2 to the right of array
        i = -1;
        for (int j = 0; j < nums.size(); j++) {
            if (nums[j] == 2) {
                i = j;
                break;
            }
        }
        if(i==-1) return;
        for (int j = i + 1; j < n; j++) {
            if (nums[j] != 2) {
                swap(nums[i], nums[j]);
                i++;
            }
        }
    }
};