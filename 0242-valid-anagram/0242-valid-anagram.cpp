class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size() != t.size()) return false;
        vector<int> arr(26);
        for(int i=0;i<s.size();i++){
            arr[t[i] - 'a']++;
            arr[s[i] - 'a']--; 
        }
        for(int a : arr)
            if(a!=0) return false;
        return true;
    }
};