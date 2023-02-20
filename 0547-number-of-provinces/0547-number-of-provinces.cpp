class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int c=0, n = isConnected.size();
        stack<int> stk;
        vector<bool> v(n,false);
        for(int i=0;i<n;i++){
            if(v[i]) continue;
            v[i]=true;
            stk.push(i);
            while(!stk.empty()){
                int t = stk.top();
                stk.pop();
                for(int j=0;j<n;j++)
                    if(!v[j] && isConnected[t][j]) {v[j]=true;stk.push(j);}
            }
            c++;
        }
        return c;
    }
};