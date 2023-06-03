class Solution {
public:
    bool validPalindrome(string s) {
        int left=0;
        int right = s.size()-1;
        int count =0;       
        return test(s, left,right,count);
    }
    bool test(string s, int left, int right, int count){
        while(left<right){
            if(s[left] == s[right]){left++;right--;}
            else if(count<1){
                return test(s, left+1, right, count+1) || test(s,left, right-1, count+1);
            }
            else return false;
        }
        return true;
    }
    
};