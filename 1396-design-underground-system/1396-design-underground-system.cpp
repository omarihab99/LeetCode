class UndergroundSystem {
public:
    unordered_map<int, pair<string, int>> check_in; // ID checkin from station in time
    unordered_map<string, pair<int, int>> check_out; // to station time count
    UndergroundSystem() {
        
    }
    
    void checkIn(int id, string stationName, int t) {
        check_in[id].first = stationName;
        check_in[id].second=t;
    }
    
    void checkOut(int id, string stationName, int t) {
        auto checkout_customer = check_in[id];
        string path = checkout_customer.first + "-" + stationName;
        check_out[path].first += (t - checkout_customer.second); // total time
        check_out[path].second++; // number of arrivals
        check_in.erase(id);
    }
    
    double getAverageTime(string startStation, string endStation) {
        string path = startStation + "-" + endStation;
        auto arrival = check_out[path];
        return (double) arrival.first / arrival.second;
    }
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */