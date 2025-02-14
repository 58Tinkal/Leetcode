class ProductOfNumbers {
    vector<int>v;
    int e = 0;
public:
    ProductOfNumbers() {
        v.push_back(1);
    }
    
    void add(int num) {
      if(num!=0) { v.push_back(num*v[e]); e++;}
      else {
        v = {1};
        e = 0;
      } 
    }
    
    int getProduct(int k) {
        int ans = 1;
        if(k >= v.size()) return 0;
        return (v[e]/v[e-k]);
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */