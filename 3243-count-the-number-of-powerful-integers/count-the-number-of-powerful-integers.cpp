#define ll long long int
class Solution {
public:
    ll dp[16][2];
    ll solve(ll idx,bool tight,ll l,string &su,string &s){

        if(idx>=s.size()){
            return 1;
        }
        if(dp[idx][tight] != -1) return dp[idx][tight];
        ll ans = 0;
        ll limit = tight ? s[idx] - '0' : 9;
        limit = min(limit,l);

        ll suIdx = s.size() - su.size();
         // idx is in the range of sufix
         if(idx >= suIdx   ){
            // if tight is false then we can fil element of our choice => we can
            // make last part as sufix
            if(tight == false) return dp[idx][tight] = 1;

              // we cannot be able to make last part as sufix
            if(s[idx] < su[idx - suIdx]) return dp[idx][tight] = 0;
             
             // we can fill the idx noe check for others;
            if(s[idx] == su[idx - suIdx]) return dp[idx][tight] = solve(idx+1,true,l,su,s);
                
                // we can match sufix
            if(s[idx] > su[idx - suIdx]) return dp[idx][tight] = 1;
         }

        // idx is not in sufix range
        for(int d=0;d<=limit;d++){
            ll newTight = tight & (d == s[idx] - '0');
            ans += solve(idx+1,newTight,l,su,s);
        }

       return dp[idx][tight] = ans;
    }
    long long numberOfPowerfulInt(long long start, long long finish, int limit, string s) {
        
        ll x = 0;
        string l = to_string(start-1);
        if(l.size()>=s.size()){
            memset(dp, -1, sizeof(dp));
            x = solve(0,1,limit,s,l);
        } 
        string h = to_string(finish);
        memset(dp, -1, sizeof(dp));
        ll y = solve(0,1,limit,s,h);

        return y - x;
    }
};