class ProductOfNumbers {
public:
    vector<int>list; 

    ProductOfNumbers() {
    }
    
    void add(int num) {
        list.push_back(num);
    }
    
    int getProduct(int k) {
        int n=list.size(),product=1;
        for(int i=n-1;i>=n-k;i--){
            product*=list[i];
        }
        return product;
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */