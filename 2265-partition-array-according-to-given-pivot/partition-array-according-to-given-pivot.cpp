class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        vector<int>s,g;
        int n = nums.size();
        for(auto &it:nums){
            if(it<pivot) s.push_back(it);
            if(it>pivot) g.push_back(it);
        }
        int x = n - (s.size() + g.size());
        while(x--) s.push_back(pivot);
        for(auto &it:g){
            s.push_back(it);
        }
        return s;
    }
};