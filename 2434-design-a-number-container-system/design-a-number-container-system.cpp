class NumberContainers {
    unordered_map<int, int> m;
    unordered_map<int, priority_queue<int, vector<int>, greater<int>>> d;

public:
    NumberContainers() {}

    void change(int index, int number) {
        if (m.count(index) && m[index] == number)
            return;
        m[index] = number;
        d[number].push(index);
    }

    int find(int number) {
        if (!d.count(number))
            return -1;
        auto& it = d[number];
        while (!it.empty() && m[it.top()] != number)
            it.pop();
        return it.empty() ? -1 : it.top();
    }
};

/**
 * Your NumberContainers object will be instantiated and called as such:
 * NumberContainers* obj = new NumberContainers();
 * obj->change(index,number);
 * int param_2 = obj->find(number);
 */