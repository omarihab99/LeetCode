class DataStream {
public:
    int val,n,y;
    DataStream(int value, int k) {
        n=-1;
        val=value;
        y=k;
    }
    
    bool consec(int num) {
        if(num==val) n++;
        else n=-1;
        if(y-n<=1) return true;
        return false;
    }
};

/**
 * Your DataStream object will be instantiated and called as such:
 * DataStream* obj = new DataStream(value, k);
 * bool param_1 = obj->consec(num);
 */