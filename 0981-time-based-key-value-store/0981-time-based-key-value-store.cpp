class TimeMap {
public:
    unordered_map<string,vector<pair<int,string>>> key_map;
    TimeMap() {
    }
    void set(string key, string value, int timestamp) {
        key_map[key].push_back({timestamp, value});
    }
    
    string get(string key, int timestamp) {
        if(key_map.find(key) == key_map.end() || timestamp < key_map[key][0].first) return "";
        int left = 0, right = key_map[key].size()-1;
        string time="";
        while(left<=right){
            int mid = (left+right)/2;
            if(key_map[key][mid].first == timestamp) return key_map[key][mid].second;
            if(key_map[key][mid].first < timestamp){
                time = key_map[key][mid].second;
                left = mid+1;
            }
            else right = mid-1;
        }
        return time;
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */