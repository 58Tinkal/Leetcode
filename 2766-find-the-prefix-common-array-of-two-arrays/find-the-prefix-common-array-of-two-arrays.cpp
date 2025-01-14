class Solution {
public:
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
        return ans;
    }
};