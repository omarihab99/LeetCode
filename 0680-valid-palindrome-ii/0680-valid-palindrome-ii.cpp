class Solution {
public:
    bool validPalindrome(string s) {
        int left=0;
        int right = s.size()-1;
        int count =0;
        while(left<right){
            if(s[left] == s[right]){left++;right--;}
            else return test(s, left+1, right) || test(s, left, right-1);     
        }
        return true;
    }
    bool test(string s, int left, int right){
        while(left<right){
            if(s[left] == s[right]){left++;right--;}
            else return false;
        }
        return true;
    }
    
};