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
        for(int i = 0; i < n; ++i){
           freq[A[i]]++;
           freq[B[i]]++;
            ans.push_back(cnt(freq));
        }
        for(auto it:ans)  cout<<it<<' ';
        return ans;
    }
};