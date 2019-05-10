class Solution {
public:
    int hammingDistance(int x, int y) {
        unsigned int num = x ^ y;
        return BitCount2(num);
    }
    // 快速消除1
    int BitCount2(unsigned int n)
    {
        unsigned int c =0 ;
        for (c =0; n; ++c)
        {
            n &= (n -1) ; 
        }
        return c ;
    }
};
