class Solution {
public:
    int largestRectangleArea(vector<int>& h) {
        int n = h.size();
        int ans = 0;
        stack<int> st;
        
        for(int i = 0; i < n; i++) {
            while(!st.empty() && h[st.top()] > h[i]) {
                int el = st.top();
                st.pop();
                int nse = i; 
                int pse = (st.empty()) ? -1 : st.top(); 
                ans = max(ans, h[el] * (nse - pse - 1));
            }
            st.push(i);
        }
        
     
        while (!st.empty()) {
            int el = st.top();
            st.pop();
            int nse = n; 
            int pse = (st.empty()) ? -1 : st.top();
            ans = max(ans, h[el] * (nse - pse - 1));
        }

        return ans;
    }
};
