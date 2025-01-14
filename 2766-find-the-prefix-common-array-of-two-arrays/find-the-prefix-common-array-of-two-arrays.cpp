class Solution {
public:
    int cnt(vector<int>&a){
          int c = 0;
          for(auto it:a) if(it == 2) c++;
          return c;
    }
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        vector<int>ans, freq(51,0);
        int n = A.size();
        int c = 0;
        for(int i = 0; i < n; ++i){
           freq[A[i]]++;
           if(freq[A[i]] == 2) c++;
           freq[B[i]]++;
           if(freq[B[i]] == 2) c++;
            ans.push_back(c);
        }
        for(auto it:ans)  cout<<it<<' ';
        return ans;
    }
};