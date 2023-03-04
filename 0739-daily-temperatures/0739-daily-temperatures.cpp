class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int> answer(n,0);
        stack<int> idx;
        stack<int> s;
        s.push(temperatures[0]);
        idx.push(0);
        for(int i=1;i<n;i++){
            int curr = temperatures[i];
            while(!s.empty() && s.top()<curr){
                int k = i-idx.top();
                answer[idx.top()] = k;
                s.pop();
                idx.pop();           
            }
            idx.push(i);
            s.push(curr);
        }
        return answer;
    }
};