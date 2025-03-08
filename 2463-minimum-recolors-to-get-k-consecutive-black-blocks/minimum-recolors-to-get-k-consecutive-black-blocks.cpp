class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int n = blocks.size();
        vector<int>p(n,0);
        for(int i=0;i<n;i++){
            if(i==0){
                p[i] = (blocks[i] == 'W')?1:0;
            }else{
                p[i] = p[i-1] + ((blocks[i] == 'W')?1:0);
            }
        }
        for(int i=0;i<n;i++)  cout<<p[i]<<' ';
        int ans = p[k-1];
        int s=0,e=k;
        while(e<n){
          int x = p[e] - p[s];
          e++; s++;
          ans = min(ans,x);
        } 
        return ans; 
    }
};