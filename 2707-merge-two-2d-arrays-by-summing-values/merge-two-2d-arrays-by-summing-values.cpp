class Solution {
public:
int findIndex(const vector<vector<int>>& vec, int target) {
    int low = 0;
    int high = vec.size() - 1;
    
    while(low <= high) {
        int mid = low + (high - low) / 2;
        
        // Compare the first element of the mid vector with target
        if(vec[mid][0] == target) {
            return mid;
        } else if(vec[mid][0] < target) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    
    // Return -1 if target is not found
    return -1;
}
    vector<vector<int>> mergeArrays(vector<vector<int>>& nums1, vector<vector<int>>& nums2) {
        
        for(auto &it:nums2){
          int idx = findIndex(nums1,it[0]);
          if(idx == -1) nums1.push_back({it[0],it[1]});
          else nums1[idx][1]+=it[1];
           sort(nums1.begin(),nums1.end());
        }
        sort(nums1.begin(),nums1.end());
        return nums1;
    }
};