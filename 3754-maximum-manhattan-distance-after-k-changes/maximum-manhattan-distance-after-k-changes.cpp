class Solution {
public:
    int maxDistance(string str, int k) {
        int n = 0, e = 0, w = 0, s = 0;
        int ans = INT_MIN;
        for (int i=0;i<str.size();i++) {
            int x = 0;
            if (str[i] == 'N')
                n++;
            if (str[i] == 'E')
                e++;
            if (str[i] == 'W')
                w++;
            if (str[i] == 'S')
                s++;
           x = min(i+1,abs(n-s)+abs(e-w)+2*k);
           ans=max(ans,x);
        }
        return ans;
    }
};