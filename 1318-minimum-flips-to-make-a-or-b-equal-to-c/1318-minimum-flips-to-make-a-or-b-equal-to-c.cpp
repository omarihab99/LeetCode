#include <bit>
class Solution {
public:
    int minFlips(int a, int b, int c) {
        return __popcount((a|b)^c) + __popcount(a&b&~c);
    }
};