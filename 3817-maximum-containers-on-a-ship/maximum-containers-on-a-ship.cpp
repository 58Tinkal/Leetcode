class Solution {
public:
    int maxContainers(int n, int w, int maxWeight) {
        int x = (maxWeight/w);
        if(x >= n*n) return n*n;
        return x;
    } 
};