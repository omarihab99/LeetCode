class ProductOfNumbers {
public:
    vector<int> v;
    ProductOfNumbers() {

    }
    
    void add(int num) {
        v.emplace_back(num);
    }
    
    int getProduct(int k) {
        int p=1;
        int n=v.size();
        for(int i=1;i<=k;i++){
            p*=v[n-i];
        }
        return p;
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */