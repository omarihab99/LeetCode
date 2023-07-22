class Solution {
public:
    vector<int> evenOddBit(int n) {
        int i=0;
        vector<int> res(2,0);
        while(n!=0){
            if((n&1) != 0){
                if ((i&1) == 0) res[0]++;
                else res[1]++;
            }
            n >>=1;
            i++;
        }
        return res;
    }
};