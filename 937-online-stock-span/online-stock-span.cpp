class StockSpanner {
public:
    stack<pair<int, int>> st; 
    int idx;
    
    StockSpanner() {
        idx = 0;
    }
    
    int next(int p) {
        int c = 1;
        
        while (!st.empty() && st.top().first <= p) {
            c += st.top().second;
            st.pop();
        }
        st.push({p, c});
        return c;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */
