class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        priority_queue<long long, vector<long long>, greater<long long>>st;
        for(auto it:nums) st.push(it);
         int ans = 0;
         while(!st.empty()){
            auto it = st.top();
            st.pop();
            if(it >= k)  return ans;
            if(st.size() == 0) return ans;
            long long x = st.top(); st.pop();
            st.push(min(it,x)*2 + max(it,x));
            ans++;
         }
       
       return ans;

    }
};