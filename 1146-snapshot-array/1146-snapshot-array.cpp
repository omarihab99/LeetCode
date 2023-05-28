class SnapshotArray {
public:
    int s_id;
    vector<vector<pair<int,int>>> arr;
    SnapshotArray(int length) {
        s_id=0;
        arr.resize(length);
        for(int i=0; i<length; i++) arr[i].push_back(make_pair(0,0));
    }
    
    void set(int index, int val) {
        arr[index].push_back(make_pair(s_id, val));
    }
    
    int snap() {
        return s_id++;
    }
    
    int get(int index, int snap_id) {
        auto it = upper_bound(arr[index].begin(), arr[index].end(), make_pair(snap_id, INT_MAX));
        return prev(it)-> second;
    }
};

/**
 * Your SnapshotArray object will be instantiated and called as such:
 * SnapshotArray* obj = new SnapshotArray(length);
 * obj->set(index,val);
 * int param_2 = obj->snap();
 * int param_3 = obj->get(index,snap_id);
 */