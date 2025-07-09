class Solution {
public:
    int maxFreeTime(int ev, int k, vector<int>& s, vector<int>& e) {
        int n = s.size();
         int x =0;
        for(int i=0;i<n;i++){
            x+=(e[i]-s[i]);
        }
        vector<int>a;
         a.push_back(s[0]);
        for(int i=1;i<n;i++){
            a.push_back(s[i]-e[i-1]);
        }
         a.push_back(ev-e[n-1]);
        for(int i=0;i<a.size();i++){
            cout<<a[i]<<' ';
        }  cout<<endl;

        
        if(a.size() == 0) return 0;
        if(a.size() <= k+1) return ev-x;

        x =0;
        for(int i=0;i<k+1;i++){
            x+=a[i];
        }
        int st=0;
        int ans = x;
        for(int i=k+1;i<a.size();i++){
            x += a[i];
            x-=a[st];
            st++;
            ans=max(ans,x);
        }
        
        
        return ans;
    }
};