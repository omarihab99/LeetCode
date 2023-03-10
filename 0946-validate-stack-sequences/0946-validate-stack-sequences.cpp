class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> s;
        int p=0;
        for(int i=0;i<pushed.size();i++){
            s.push(pushed[i]);
            while(!s.empty() && p<popped.size() && s.top() == popped[p]){
                s.pop();
                p++;
            }
        }
        if(p==popped.size()) return true;
        return false;
    }
};