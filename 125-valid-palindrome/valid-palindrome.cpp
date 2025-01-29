class Solution {
public:
    bool check(string &s){
        int i=0,j=s.size()-1;
        while(i<j){
            if(s[i]!=s[j]) return false;
            i++;j--;
        }
        return true;
    }
    bool isPalindrome(string s) {
        string str;
        for(int i=0;i<s.size();i++){
            if(s[i]>='A' && s[i] <= 'Z'){
                int x = s[i] - 'A';
                char c = 'a' + x;
                str.push_back(c);
            }else if(s[i]>='a' && s[i] <='z') str.push_back(s[i]);
            else if(s[i]>='0' && s[i] <= '9') str.push_back(s[i]);
            else continue;
        }
        return check(str);
    }
};