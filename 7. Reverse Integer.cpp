class Solution {
public:
    int reverse(int x) {
        long result = 0 ;
        while ( x != 0 ) {
            result = 10 * result + x % 10 ;
            x = x / 10 ;
        } // while

        if ( INT_MIN < result && result < INT_MAX )
            return result ;
        return 0 ;
    }
};
