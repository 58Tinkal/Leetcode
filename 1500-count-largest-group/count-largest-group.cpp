class Solution {
public:
    int fun(int n){
        int x = 0;
        while(n > 0){
            x += n % 10;
            n = n / 10;
        }
        return x;
    }

    int countLargestGroup(int n) {
        map<int, int> m;
        for(int i = 1; i <= n; i++){
            int x = fun(i);
            m[x]++;
        }

        int maxGroupSize = 0;
        for(auto it : m){
            maxGroupSize = max(maxGroupSize, it.second);
        }

        int count = 0;
        for(auto it : m){
            if(it.second == maxGroupSize) count++;
        }

        return count;
    }
};
