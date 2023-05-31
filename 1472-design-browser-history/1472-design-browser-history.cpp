class BrowserHistory {
public:
    vector<string> history;
    int current;
    BrowserHistory(string homepage) {
        history.push_back(homepage);
        current =0;
    }
    
    void visit(string url) {
        history.erase(history.begin()+current+1, history.end());
        history.push_back(url);
        current++;
    }
    
    string back(int steps) {
        if(current-steps <= 0){
            current=0;
            return history[0];
        }
        current -= steps; 
        return history[current];
    }
    
    string forward(int steps) {
        if(current+steps>= history.size()-1){
            current = history.size()-1;
            return history[current];
        }
        current += steps;
        return history[current];
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */