class StockSpanner {
public:
    stack<pair<int, int>> st;
    int idx;
    StockSpanner() { idx = -1; }

    int next(int price) {
        idx++;
        while (!st.empty() && st.top().first <= price)
            st.pop();
        int i = (st.empty()) ? -1 : st.top().second;
        st.push({price, idx});
        return idx - i;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */