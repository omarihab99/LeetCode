class Solution {
public:
    char bs(vector<char>& letters, char target, int l, int r, int last){
        if(r>=l){
            int mid = (l+r)/2; 
            if(letters[mid] > target) {
                last = mid;
                return bs(letters, target, l, mid-1,last); 
            }
            if(letters[mid] <= target) return bs(letters, target, mid+1, r,last);
            
        }
        return letters[last];
    }
    char nextGreatestLetter(vector<char>& letters, char target) {
        return bs(letters, target, 0, letters.size()-1,0);
    }
};