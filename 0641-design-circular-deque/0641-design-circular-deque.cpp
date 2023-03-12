class MyCircularDeque {
public:
    vector<int> q;
    int s =0;
    MyCircularDeque(int k) {
        s=k;
        q.reserve(k);
    }
    
    bool insertFront(int value) {
        if(q.size() < s)
        {
            q.insert(q.begin(), value);
            return true;
        }
        return false;
            
        
    }
    
    bool insertLast(int value) {
        if(q.size() < s){
            q.emplace_back(value);
            return true;
        }
        return false;
    }
    
    bool deleteFront() {
        if(!q.empty()){
            q.erase(q.begin());
            return true;
        }
        return false;
    }
    
    bool deleteLast() {
        if(!q.empty())
        {
            q.pop_back();
            return true;
        }
        return false;
        
    }
    
    int getFront() {
        if(!q.empty())
            return q.front();
        return -1;
    }
    
    int getRear() {
        if(!q.empty())
            return q.back();
        return -1;
    }
    
    
    bool isEmpty() {
        return q.empty();
    }
    
    bool isFull() {
        if(q.size()==s) return true;
        return false;
    }
};

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */