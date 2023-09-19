class Cashier {
    double dis;
    int n;
    HashMap<Integer,Integer> p = new HashMap();
    int c;
    public Cashier(int n, int discount, int[] products, int[] prices) {
        this.n=n;
        dis= (100-discount) / 100.000;
        c=0;
        for(int i=0;i<products.length;i++){
            p.put(products[i], prices[i]);
        }
    }
    public double getBill(int[] product, int[] amount) {
        c++;
        int subtotal=0;
        for(int i=0;i<product.length;i++){
            subtotal += (p.get(product[i]) * amount[i]);
        }
        if(c==this.n){
            c=0; 
            return  subtotal * dis;
        }
        return (double) subtotal;
        
    }
}

/**
 * Your Cashier object will be instantiated and called as such:
 * Cashier obj = new Cashier(n, discount, products, prices);
 * double param_1 = obj.getBill(product,amount);
 */