class Solution {
public:
    unordered_set<string> st;
    void buildSet() {
        //2^p from p = 0 to 29
        //convert to string
        //sort it
        //store it in st
        for(int p = 0; p <= 29; p++) {
            string s = to_string(1 << p);
            sort(begin(s), end(s));
            st.insert(s);  
        }
    }

    bool reorderedPowerOf2(int n) {
        if(st.empty()) {
            buildSet(); //call only once (static)
        }

        string s = to_string(n);
        sort(begin(s), end(s));

        return st.count(s);
    }
};