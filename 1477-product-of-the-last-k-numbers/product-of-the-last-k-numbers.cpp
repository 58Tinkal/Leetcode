class ProductOfNumbers {
    vector<int>v;
    int e = -1;
public:
    ProductOfNumbers() {
        
    }
    
    void add(int num) {
        v.push_back(num);
        e++;
    }
    
    int getProduct(int k) {
        int ans = 1;
        int i = e;
        for(;i>e-k;i--){
            ans = ans*v[i];
        }
        return ans;
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */