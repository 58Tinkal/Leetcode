class Solution {
public:
string decimalToBase3(int n) {
    if (n == 0) return "0";  // Edge case for zero
    
    string result = "";
    while (n > 0) {
        result = char('0' + (n % 3)) + result;  // Prepend remainder
        n /= 3;
    }
    return result;
}
    bool checkPowersOfThree(int n) {
        string s = decimalToBase3(n);
        cout<<s<<endl;
        for(auto &it:s){
            if(it == '2') return false;
        }
        return true;
    }
};