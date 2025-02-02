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
           int a=n,b=s,c=e,d=w,K=k;
           if(a>=b){
               if(b>=K){
                 a+=K;
                  b-=K;
                  K=0;
               }else{
                  a+=b;
                 K-=b;
                 b=0;
               }
           }else{
                if(a>=K){
                   b+=K;
                   a-=K;
                   K=0;
                }else{
                   b+=a;
                   K-=a;
                   a=0;
                }
           }
           if(c>=d){
               if(d>=K){
                  c+=K;
                  d-=K;
                  K=0;
               }else{
                  c+=d;
                  K-=d;
                  d=0;
               }
           }else{
               if(c>=K){
                  d+=K;
                  c-=K;
                  K=0;
               }else{
                  d+=c;
                  K-=c;
                  c=0;
               }
           }
           ans = max(ans,abs(a-b)+abs(c-d));
        }
        return ans;
    }
};