class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        vector<int>s;
        int c = 0;
        for(auto &it:nums){
            if(it < pivot) s.push_back(it);
            if(it == pivot) c++;
        }
        while(c--) s.push_back(pivot);
        for(auto &it:nums){
           if(it>pivot) s.push_back(it);
        }
        return s;
    }
};