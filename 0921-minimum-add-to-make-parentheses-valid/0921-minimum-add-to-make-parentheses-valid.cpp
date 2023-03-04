class Solution {
public:
    int minAddToMakeValid(string s) {
        if(s=="") return 0;
        stack<char> st;
        st.push(s[0]);
        for(int i=1;i<s.size();i++){
            if(s[i]== ')' && !st.empty() && st.top() == '('){
                st.pop();
            }
            else{
                st.push(s[i]);
            }
        }
        return st.size();
    }
};