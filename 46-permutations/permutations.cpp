class Solution {
public:
vector<vector<int>>ans;
   void fun(int idx,vector<int>&a){
       if(idx == a.size()){
        ans.push_back(a);
        return;
       }
       for(int i=idx;i<a.size();i++){
        swap(a[idx],a[i]);
        fun(idx+1,a);
        swap(a[idx],a[i]);
       }
   }
    vector<vector<int>> permute(vector<int>& nums) {
        fun(0,nums);
        return ans;
    }
};